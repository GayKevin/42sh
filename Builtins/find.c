/*
** find.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:09:19 2014 Maxime Limone
** Last update Mon May  5 14:35:05 2014 Kevin Gay
*/

#include <unistd.h>
#include "main.h"
#include "my_strcmp.h"
#include "my_show_tab.h"
#include "unsetenv.h"
#include "setenv.h"

int		find_env(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "env") == 0)
    {
      my_show_tab(sh->env);
      sh->ch = 1;
      return (-1);
    }
  return (0);
}

int		find_unsetenv(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "unsetenv") == 0)
    {
      unset_env(sh, i);
      sh->ch = 1;
      return (-1);
    }
  return (0);
}

int		find_setenv(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "setenv") == 0)
    {
      set_env(sh, i);
      sh->ch = 1;
      return (-1);
    }
  return (0);
}
