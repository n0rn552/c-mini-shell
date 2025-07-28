#include <stdio.h>
#include <string.h>
#define SIZE 250

typedef struct 
{
    const char *name;
    void (*func)(char **args);
}Command;

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

int main()
{
    char buffer[SIZE];
    char *args[SIZE];
    char *cmd;

    while(1)
    {
        printf("> ");
        fflush(stdout);

        if(fgets(buffer, SIZE, stdin) == NULL)
        {
            printf("\n>\n");
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        cmd = strtok(buffer, " \t");
        if(cmd == NULL) continue;

        int nArgs = 0;  
        while((args[nArgs] = strtok(NULL, " \t")) != NULL)
            nArgs++;

        args[nArgs] = NULL;
    }

    return 0;
}