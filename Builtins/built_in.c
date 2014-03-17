/*
** built_in.c for builtin in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Mar 12 11:01:09 2014 Kevin Gay
** Last update Mon Mar 17 12:03:23 2014 Kevin Gay
*/

#include <unistd.h>
#include "struct.h"

int	built_in(t_shell *sh)
{
  int	i;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      if (find_cd(sh, i) == 1)
	return (0);
      if (my_strcmp(sh->cmd[i], "exit") == 0)
	{
	  if (sh->cmd[i + 1] != NULL)
	    sh->re = my_getnbr(sh->cmd[i + 1]);
	  my_free(sh->cmd);
	  return (1);
	}
      if (find_env(sh, i) == 1)
	return (0);
      if (find_unsetenv(sh, i) == 1)
	return (0);
      if (find_setenv(sh, i) == 1)
	return (0);
    }
  return (0);
}
