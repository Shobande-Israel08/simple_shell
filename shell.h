#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char **argv);
char *get_location(char *command);

void next_print(const char *message);
void display_prompt(void);
/*void read_command(char *command, size_t size);*/
void execute_command(const char *command);

#endif /* SHELL_H */
