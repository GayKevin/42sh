/*
** unsetenv.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:42:22 2014 Maxime Limone
** Last update Mon May 19 12:54:50 2014 Maxime Limone
*/

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "my_free.h"
#include "my_strcat.h"
#include "unsetenv.h"
#include "my_printf_error.h"
#include "my_putstr.h"

int		find_unset_env(t_shell *sh, int l, int i)
{
  if (my_strcmp_(sh->cmd[i + 1], sh->env[l]) == 0)
    return (0);
  return (-1);
}

int		unset_env(t_shell *sh, int i)
{
  if (sh->cmd[i + 1] == NULL)
    printf_err("Usage: unsetenv [variable name1] %s\n"
	       , "[variable name2] ...");
  while (sh->cmd[i + 1] != NULL)
    {
      if (strncmp(sh->cmd[i + 1], "PATH", 4) == 0)
	{
	  my_free(sh->path);
	sh->path = NULL;
	}
      unset_var(i, sh);
      i++;
    }
  return (0);
}

int		unset_var(int i, t_shell *sh)
{
  int		l;

  l = -1;
  while (sh->env[++l] != NULL)
    {
      if (find_unset_env(sh, l, i) == 0)
	{
	  free(sh->env[l]);
	  while (sh->env[l] != NULL)
	    {
	      sh->env[l] = sh->env[l + 1];
	      l++;
	    }
	  return (0);
	}
    }
  if (sh->env[l] == NULL)
    printf_err("'%s' environment variable not found\n"
	       , my_strcut_char(sh->cmd[i + 1], '='));
  return (0);
}
