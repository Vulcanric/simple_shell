#ifndef MAIN_H
#define MAIN_H
/*  Header files  */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes*/
void display_prompt(void);
void handle_cmd(char **env, char *line_ptr, char *delim, char *prog);
char *path(char *cmd);
char *_strcat(char *dest, char *src);
void _perror(char *cmd, char *prog);
void print_num(int n);
#endif
