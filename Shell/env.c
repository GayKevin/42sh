/*
** env.c for env in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Mar 12 23:13:35 2014 Kevin Gay
** Last update Thu Mar 13 13:38:07 2014 Kevin Gay
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void	get_env(t_shell *sh, char **env)
{
  int	i;
  int	l;

  i = -1;
  l = 0;
  if (env != NULL)
    {
      while (env[++i] != NULL)
      	l++;
      sh->env = malloc(sizeof(char *) * (l + 3));
      i = -1;
      while (env[++i] != NULL)
      	{
      	  sh->env[i] = malloc(sizeof(char) * strlen(env[i]) + 2);
	  memset(sh->env[i], 0, strlen(env[i] + 2));
      	  strcpy(sh->env[i], env[i]);
      	}
      sh->env[i] = NULL;
    }
}
