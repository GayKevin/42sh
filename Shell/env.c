/*
** env.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:24:25 2014 Maxime Limone
** Last update Wed May 14 11:43:11 2014 Kevin Gay
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int	get_env(t_shell *sh, char **env)
{
  int	i;
  int	l;

  i = -1;
  l = 0;
  if (env != NULL)
    {
      while (env[++i] != NULL)
      	l++;
      if ((sh->env = malloc(sizeof(char *) * (l + 2))) == NULL)
	return (-1);
      i = -1;
      while (env[++i] != NULL)
      	{
      	  sh->env[i] = malloc(sizeof(char) * (strlen(env[i]) + 2));
	  if (sh->env[i] == NULL)
	    return (-1);
	  memset(sh->env[i], 0, (strlen(env[i] + 2)));
      	  strcpy(sh->env[i], env[i]);
	}
      sh->env[i] = NULL;
    }
  return (0);
}
