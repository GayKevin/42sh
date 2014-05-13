/*
** dollar.c for dollar in /home/gay_k/rendu/42sh/Shell
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 02:29:24 2014 Kevin Gay
** Last update Tue May 13 16:17:22 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "setenv.h"
#include "my_strncpy.h"
#include "my_strcat.h"

int	compare_env_dollar(char *tmp, t_shell *sh, int p)
{
  if(my_strcmp_dollar(tmp, sh->env[p], strlen(tmp)) == 0)
    return (0);
  return(-1);
}

int	find_dollar(t_shell *sh)
{
  int	i;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      if (strncmp(sh->cmd[i], "$", 1) == 0)
	if (sh->cmd[i][1] != '\0')
	  return (i);
    }
  if (sh->cmd[i] == NULL)
      return (-1);
  return (0);
}

int	use_dollar(t_shell *sh, int i, int l, char *tmp)
{
  int	p;
  int	r;

  r = 0;
  p = -1;
  while (sh->env[++p] != NULL)
    {
      if (compare_env_dollar(tmp, sh, p) == 0)
	{
	  while (sh->env[p][++l] != '=');
	  if ((sh->cmd[i] = realloc(sh->cmd[i], sizeof(char *) *
				    strlen(sh->env[p]))) == NULL)
	    return (-1);
	  memset(sh->cmd[i], 0, strlen(sh->env[p]));
	  my_strncpy(sh->cmd[i], sh->env[p], (l + 1));
	  r = 1;
	}
    }
  if (r != 1)
    {
      my_putstr("\n");
      sh->ch = 1;
    }
  return (0);
}


int	dollar(t_shell *sh)
{
  int	i;
  int	l;
  char	*tmp;

  l = -1;
  i = -1;
  if ((i = find_dollar(sh)) == -1)
    return (1);
  if ((tmp = malloc(sizeof(char) * (strlen(sh->cmd[i]) + 2))) == NULL)
    return (-1);
  memset(tmp, 0, (strlen(sh->cmd[i]) + 2));
  my_strncpy(tmp ,sh->cmd[i], 1);
  use_dollar(sh, i, l ,tmp);
  free(tmp);
  return (0);
}
