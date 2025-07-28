#include <stdio.h>
#include <string.h>
#include "commands.h"
#define SIZE 250

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

        parse(buffer, &cmd, args);
        handle_command(cmd, args);
    }

    return 0;
}