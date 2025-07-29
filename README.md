# Mini Shell in C

This is a **learning project** aimed at practicing system programming concepts in C, such as process creation, command parsing, and basic shell features.


## Features

- Built-in commands:  
  - `cd` — change directory  
  - `exit` — exit with optional return code  
  - `echo` — print arguments  
  - `pwd` — print current directory  
- Execute external commands with arguments (e.g., `ls -l`, `date`, `cat file.txt`)  
- Error handling:  
  - Messages for invalid commands and arguments  
  - Handling errors from `fork()`, `execvp()`, and `chdir()`


## Build and Run

```bash
gcc -Wall -Wextra main.c commands.c -o mini-shell
./mini-shell

## Build and Run

```bash
gcc -Wall -Wextra main.c commands.c -o mini-shell
./mini-shell
````

## Usage

After launching, the shell shows a prompt `>`. You can type commands here.

Examples:

```bash
> pwd
/home/user
> cd ..
> echo Hello World
> ls -l
> exit 0
```

## Project Structure

* `main.c` — Entry point, main logic for input reading and parsing
* `commands.c` — Implementations of built-in commands and external command execution
* `commands.h` — Header file with function and struct declarations
