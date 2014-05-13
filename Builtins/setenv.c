/*
** setenv.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
x** Started on  Mon May  5 11:23:51 2014 Maxime Limone
** Last update Tue May 13 11:57:12 2014 Kevin Gay
*/

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "my_strcat.h"

int		compare_env(t_shell *sh, int i, int p)
{
  if (my_strcmp_(sh->cmd[i + 1], sh->env[p]) == 0)
    return (0);
  return (-1);
}

int		edit_env(t_shell *sh, int l, int i, int p)
{
  while (sh->cmd[i + 1][l] != '\0')
    {
      sh->env[p][l] = sh->cmd[i + 1][l];
      l++;
    }
  sh->env[p][l] = '\0';
  return (0);
}

int		add_env(t_shell *sh, int i, int p)
{
  char		t;
  int		l;

  t = 0;
  l = -1;
  while (sh->cmd[i + 1][++l] != '\0')
    {
      if (sh->cmd[i + 1][l] == '=')
	t = 1;
    }
  if (t == 1)
    {
      if ((sh->env = realloc(sh->env, sizeof(char *) * (p + 2))) == NULL)
	return (-1);
      if (((sh->env)[p] = malloc(sizeof(char) *
				 (strlen(sh->cmd[i + 1]) + 2))) == NULL)
	return (-1);
      memset(sh->env[p], 0, strlen(sh->cmd[i + 1]));
      sh->env[p] = strcpy(sh->env[p], sh->cmd[i + 1]);
      sh->env[p + 1] = NULL;
    }
  return (0);
}

int		set_env(t_shell *sh, int i)
{
  int		p;
  int		l;

  p = -1;
  l = 0;
  if (sh->cmd[i + 1] == NULL)
    return (0);
  while (sh->env[++p] != NULL)
    {
      if (compare_env(sh, i, p) == 0)
	if (edit_env(sh, l, i, p) == 0)
	  return (0);
    }
  add_env(sh, i, p);
  return (0);
}
