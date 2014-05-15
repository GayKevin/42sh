/*
** execve.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:24:41 2014 Maxime Limone
<<<<<<< HEAD
** Last update Thu May 15 13:49:15 2014 Kevin Gay
=======
** Last update Wed May 14 16:38:06 2014 Kevin Gay
>>>>>>> Kevin
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "my_strcat.h"
#include "my_printf_error.h"
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
      wait(&status);
      if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	sh->ok_cmd = 1;
      if (WIFSIGNALED(status)) {
	printf("tué par le signal %d\n", WTERMSIG(status));}
      if (status == 139)
      	printf_error("Segmentation Fault\n");
    }
  else if (pid == 0)
    {
      if ((execve(path, cmd, env)) == -1)
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
      if (WIFSIGNALED(status)) {
	printf("tué par le signal %d\n", WTERMSIG(status));}
	    if (status == 139)
	      printf_error("Segmentation Fault\n");
	  }
        else if (pid == 0)
	  if ((execve(cmd[i], cmd, NULL)) == -1)
	    return (0);
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
