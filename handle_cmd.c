#include "main.h"

void handle_cmd(char **env, char *line_ptr, char *delim)
{
  pid_t pid;
  int state;
  char *cmd;
  struct stat st;
  char *argv[] = {"", NULL};

  cmd = strtok(line_ptr, " \n");

  if (stat(cmd, &st) == 0)
  {
    pid = fork();

    if (pid == 0)
    {
      if (execve(cmd, argv, env) == -1)
        perror("/shell");
    }
    else
    {
      wait(&state);
    }
  }
}