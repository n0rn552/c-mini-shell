#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>  
#include <sys/wait.h>
#include "commands.h"
#define SIZE 500

Command commands[] = {
    {"cd", cmd_cd},
    {"exit", cmd_exit},
    {"echo", cmd_echo},
    {"pwd", cmd_pwd},
    {NULL, NULL}
};

void cmd_cd(char **args)
{
    char *path = args[0];

    if(path == NULL)
    {
        if((path = getenv("HOME")) == NULL)
        {
            printf("Error: HOME not set\n");
            return;
        }
    }

    if(chdir(path) != 0)
    {
        perror("Error");
    }
}


void cmd_exit(char **args)
{
    int code = 0;
    int valid = 1;
    char *p = args[0];
    if(p != NULL)
    {
        if(*p == '+' || *p == '-') p++;
        while (*p)
        {
            if(!isdigit(*p)){
                valid = 0;
                break;
            }
            p++;
        }
        
        if(valid)
        {
            code = atoi(args[0]);
        }
        else
        {
            printf("Exit: invalid argument %s\n", args[0]);
            code = 1;
        }
    }

    printf("Exitting with code %d\n", code);
    exit(code);
}


void cmd_echo(char **args)
{
    for(int i = 0; args[i] != NULL; i++)
        printf(" %s", args[i]);
    printf("\n");
}


void cmd_pwd(char **args)
{
    (void)args;
    char path[500];
    if((getcwd(path, sizeof(path)) != NULL))
        printf("%s\n", path);
    else
        printf("Error: pwd can not read your directory\n");
}


void handle_command(char *cmd, char **args)
{
    for(int i = 0; commands[i].name != NULL; i++)
    {
        if(!strcmp(commands[i].name, cmd))
        {
            commands[i].func(args);
            return;
        }
    }

    cmd_external(cmd, args);
}

void parse(char *buf, char **cmd, char **args)
{
    *cmd = strtok(buf, " \t");
    if(*cmd == NULL) return;

    int nArgs = 0;  
    while((args[nArgs] = strtok(NULL, " \t")) != NULL)
        nArgs++;

    args[nArgs] = NULL;
}


void cmd_external(char *cmd, char **args)
{
    pid_t pid = fork();

    if(pid == 0)
    {
        execvp(cmd, args);
        
        perror("Error");
        exit(1);
    }
    else if(pid > 0)
        waitpid(pid, NULL, 0);
    else
    {
        perror("Error");
    }
}
