/*
** path.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:53:58 2014 Maxime Limone
** Last update Tue May 13 20:07:53 2014 Kevin Gay
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

int	path(t_shell *sh, char *env)
{
  int	l;

  l = 3;
  sh->o = 4;
  sh->j = 0;
  sh->p = 0;
  sh->a = 1;
  while (env[l++] != '\0')
    if (env[l] == 58)
      sh->a = sh->a + 1;
  if ((sh->path = malloc(sizeof(char *) * sh->a + 8)) == NULL)
    return (-1);
  while (env[sh->o++] != '\0')
    {
      l = 0;
      if ((sh->path[sh->j] = malloc(sizeof(char) * 2048)) == NULL)
	return (-1);
      memset(sh->path[sh->j], 0, 512);
      while ((env[sh->o] != ':') && (env[sh->o] != '\0'))
	sh->path[sh->j][l++] = env[sh->o++];
      sh->path[sh->j][l++] = '/';
      sh->path[sh->j++][l] = '\0';
    }
  sh->path[sh->j] = NULL;
  return (0);
}

int	find_path(t_shell *sh)
{
  int	i;
  int	p;

  p = 0;
  i = -1;
  if (sh->env[0] == NULL)
    sh->path = NULL;
  else
    while (sh->env[++i] != '\0')
      {
	if ((strncmp(sh->env[i], "PATH=", 5)) == 0)
	  {
	    p = 1;
	    if ((path(sh, sh->env[i])) == -1)
	      return (-1);
	  }
	if (p == 0)
	  sh->path = NULL;
      }
  return (0);
}
