/*
** cd.c for cd in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Mar 12 11:09:37 2014 Kevin Gay
** Last update Thu Mar 13 17:16:01 2014 Kevin Gay
*/

#include <unistd.h>
#include "struct.h"

int	find_cd(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "cd") == 0)
    {
      if (chdir(sh->cmd[i + 1]) == -1)
	return (1);
      sh->ch = 1;
      return (1);
    }
  return (0);
}

int	find_env(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "env") == 0)
    {
      my_show_tab(sh->env);
      sh->ch = 1;
      return (1);
    }
  return (0);
}

int	find_unsetenv(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "unsetenv") == 0)
    {
      unset_env(sh, i);
      sh->ch = 1;
      return (1);
    }
  return (0);
}

int	find_setenv(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "setenv") == 0)
    {
      set_env(sh, i);
      sh->ch = 1;
      return (1);
    }
  return (0);
}
