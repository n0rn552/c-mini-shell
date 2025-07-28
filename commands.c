#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"

Command commands[] = {
    {"cd", cmd_cd},
    {"exit", cmd_exit},
    {"echo", cmd_echo},
    {"pwd", cmd_pwd},
    {NULL, NULL}
};

void cmd_cd(char **args)
{
    puts("Its cd");
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
            printf("> Exit: invalid argument %s\n", args[0]);
            code = 1;
        }
    }

    printf("> Exitting with code %d\n", code);
    exit(code);
}


void cmd_echo(char **args)
{
    printf(">");
    for(int i = 0; args[i] != NULL; i++)
        printf(" %s", args[i]);
    printf("\n");
}


void cmd_pwd(char **args)
{
    puts("Its pwd");
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
    printf("Erorr: unknown command\n");
}

void parse(char *buf, char **cmd, char **args)
{
    *cmd = strtok(buf, " \t");
    if(cmd == NULL) return;

    int nArgs = 0;  
    while((args[nArgs] = strtok(NULL, " \t")) != NULL)
        nArgs++;

    args[nArgs] = NULL;
}