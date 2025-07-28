#include <stdio.h>
#include <string.h>
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
    }

    return 0;
}