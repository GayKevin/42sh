/*
** execve.c for execve in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Mar 12 10:55:07 2014 Kevin Gay
** Last update Fri Mar 14 14:19:00 2014 Kevin Gay
*/

#include <unistd.h>
#include <sys/wait.h>
#include "struct.h"

int	exec_cmd(char *path, char **cmd, char **env, int *ch)
{
  pid_t	pid;
  int	status;

  *ch = 1;
  pid = fork();
  if (pid > 0)
    wait(&status);
  else if (pid == 0)
    if ((execve(path, cmd, env)) == -1)
      return (0);
  return (0);
}

void	check_point_slash(t_shell *sh, char **env)
{
  int	i;
  int	l;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      l  = -1;
      while (sh->cmd[i][++l] != '\0')
	{
	  if (sh->cmd[i][l] == '.' && sh->cmd[i][l + 1] == '/')
	    if (i ==  0)
	      exec_cmd(sh->path[0], sh->cmd, env, &sh->ch);
	}
    }
}
