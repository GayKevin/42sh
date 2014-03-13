/*
** setenv.c for setenv in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Thu Mar 13 17:05:59 2014 Kevin Gay
** Last update Thu Mar 13 18:29:07 2014 Kevin Gay
*/

#include <string.h>
#include <stdlib.h>
#include "struct.h"

int	compare_env(t_shell *sh, int i, int p)
{
  if (my_strcmp_(sh->cmd[i + 1], sh->env[p]) == 0)
    return (0);
  return (1);
}

int	edit_env(t_shell *sh, int l, int i, int p)
{
  while (sh->cmd[i + 1][l] != '\0')
    {
      sh->env[p][l] = sh->cmd[i + 1][l];
      l++;
    }
  sh->env[p][l] = '\0';
  return (0);
}

int	add_env(t_shell *sh, int i, int p)
{
  int	l;
  int	t;

  t = 0;
  l = 0;
  while (sh->cmd[i + 1][l] != '\0')
    {
      if (sh->cmd[i + 1][l] == '=')
	t = 1;
      l++;
    }
  if (t == 1)
    {
      if ((sh->env = realloc(sh->env, sizeof(char *) * (p + 2))) == NULL)
      return (-1);
      (sh->env)[p] = malloc(sizeof(char) * (strlen(sh->cmd[i + 1]) + 2));
      memset(sh->env[p], 0, strlen(sh->cmd[i + 1]));
      sh->env[p] = strcpy(sh->env[p], sh->cmd[i + 1]);
      sh->env[p + 1] = NULL;
    }
  return (0);
}

int	set_env(t_shell *sh, int i)
{
  int	p;
  int	l;

  p = -1;
  l = 0;
  if (sh->cmd[i] == NULL)
    return (0);
  while (sh->env[++p] != NULL)
    {
      if (compare_env(sh, i, p) == 0)
	if (edit_env(sh, l, i, p) == 0)
	  return (0);
    }
  my_put_nbr(p);
  add_env(sh, i, p);
  return (0);
}

