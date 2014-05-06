/*
** built_in.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 10:57:39 2014 Maxime Limone
** Last update Tue May  6 15:28:50 2014 Kevin Gay
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "cd.h"
#include "find.h"
#include "my_free.h"

int		built_in(t_shell *sh)
{
  int		i;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      if (find_cd(sh, i) == -1)
	return (0);
      if (strncmp(sh->cmd[i], "exit", 4) == 0)
	{
	  if (sh->cmd[i + 1] != NULL)
	    sh->re = atoi(sh->cmd[i + 1]);
	  my_free(sh->cmd);
	  return (-1);
	}
      if (find_env(sh, i) == -1)
	return (0);
      if (find_unsetenv(sh, i) == -1)
	return (0);
      if (find_setenv(sh, i) == -1)
	return (0);
    }
  return (0);
}
