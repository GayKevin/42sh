/*
** execve.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:24:41 2014 Maxime Limone
** Last update Thu May 22 01:25:22 2014 Maxime Limone
*/

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "my_strcat.h"
#include "tree.h"

int		exec_cmd(char *path, char **cmd, char **env, t_shell *sh)
{
  pid_t		pid;
  int		status;

  sh->ch = 1;
  if ((pid = fork()) == -1)
    return (0);
  if (pid > 0)
    {
      //      printf("1\n");
      wait(&status);
      //printf("2\n");
      if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	sh->ok_cmd = 1;
      else
	sh->ok_cmd = -1;
      if (status == 139)
      	fprintf(stderr, "Segmentation Fault\n");
    }
  else if (pid == 0)
    {
      /* if (setpgid(0, 0) == -1) */
      /* 	return (-1); */
      if (execve(path, cmd, env) == -1)
	exit (0);
    }
  return (0);
}

int		exec_slah_bin(char **cmd, t_shell *sh)
{
  pid_t		pid;
  int		status;
  int		i;

  i = -1;
  while (cmd[++i] != NULL)
    if (cmd[i][0] == '/')
      {
	if ((pid = fork()) == -1)
	  return (0);
	if (pid > 0)
	  {
	    wait(&status);
	    if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	      sh->ok_cmd = 1;
	    if (status == 139)
	      fprintf(stderr, "Segmentation Fault\n");
	  }
        else if (pid == 0)
	  {
	    if (setpgid(0, 0) == -1)
	      return (-1);
	    if ((execve(cmd[i], cmd, NULL)) == -1)
	      return (0);
	  }
	sh->ch = 1;
      }
  return (0);
}

int	check_point_slash(t_shell *sh, char **env)
{
  int	i;
  int	l;
  char	*path;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      l  = -1;
      while (sh->cmd[i][++l] != '\0')
	{
	  if (sh->cmd[i][0] == '.' && sh->cmd[i][1] == '/')
	    {
	      if ((path = malloc(sizeof(char) * 1024)) == NULL)
		return (-1);
	      memset(path, 0, 1024);
	      path = getcwd(path, 1024);
	      my_strcat_slash(path, sh->cmd[i]);
	      exec_cmd(path, sh->cmd, env, sh);
	      free(path);
	      return (0);
	    }
	}
    }
  return (0);
}
