/*
** unsetenv.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:42:22 2014 Maxime Limone
** Last update Mon May  5 19:54:46 2014 Maxime Limone
*/

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "my_free.h"
#include "my_strcat.h"

int		find_unset_env(t_shell *sh, int l, int i)
{
  if (my_strcmp_(sh->cmd[i + 1], sh->env[l]) == 0)
    return (0);
  return (-1);
}

int		unset_env(t_shell *sh, int i)
{
  int		l;

  l = -1;
  if (sh->cmd[i + 1] == NULL)
    return (-1);
  if (strncmp(sh->cmd[i + 1], "PATH", 4) == 0)
    {
      my_free(sh->path);
      sh->path = NULL;
    }
  while (sh->env[++l] != '\0')
    {
      if (find_unset_env(sh, l, i) == 0)
	{
	  free(sh->env[l]);
	  while (sh->env[l] != '\0')
	    {
	      sh->env[l] = sh->env[l + 1];
	      l++;
	    }
	}
      if (sh->env[l] == '\0')
	return (0);
    }
  return (0);
}
