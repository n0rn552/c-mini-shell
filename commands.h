#ifndef COMMANDS_H
#define COMMAND_H

typedef struct 
{
    const char *name;
    void (*func)(char **args);
}Command;

void handle_command(char *cmd, char **args);
void parse(char *buf, char **cmd, char **args);

#endif