#include <stdio.h>
#include <string.h>
#include "commands.h"

Command commands[] = {
    {"cd", NULL},
    {"exit", NULL},
    {"echo", NULL},
    {"pwd", NULL},
    {NULL, NULL}
};


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