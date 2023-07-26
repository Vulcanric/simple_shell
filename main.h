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
#include <errno.h>

/* Prototypes*/
void display_prompt(void);
void handle_cmd(char **env, char *line_ptr, char *delim);
int _strcmp(char *s1, char *s2);
char *path(char *cmd);
char *_strcat(char *dest, char *src);
void _perror(char *cmd);
void checkpath(char **arr, char **env, struct stat **st, char *line_ptr);
void print_num(int n);
#endif
