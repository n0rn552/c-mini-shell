#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct 
{
    const char *name;
    void (*func)(char **args);
}Command;

void cmd_cd(char **args);
void cmd_exit(char **args);
void cmd_echo(char **args);
void cmd_pwd(char **args);
void cmd_external(char *cmd, char **args);



void handle_command(char *cmd, char **args);
void parse(char *buf, char **cmd, char **args);

#endif