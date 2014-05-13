/*
** dollar.c for dollar in /home/gay_k/rendu/42sh/Shell
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 02:29:24 2014 Kevin Gay
** Last update Tue May 13 13:44:37 2014 Kevin Gay
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
  if(my_strcmp_(tmp, sh->env[p]) == 0)
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
	if (sh->cmd[i] != '\0')
	  return (i);
    }
  if (sh->cmd[i] == NULL)
      return (-1);
  return (0);
}

int	dollar(t_shell *sh)
{
  int	i;
  int	p;
  int	l;
  char	*tmp;

  l = -1;
  i = -1;
  p = -1;
  if ((i = find_dollar(sh)) == -1)
    return (1);
  tmp = malloc(sizeof(char) * (strlen(sh->cmd[i]) + 2));
  memset(tmp, 0, (strlen(sh->cmd[i]) + 2));
  my_strncpy(tmp ,sh->cmd[i], 1);
    while (sh->env[++p] != NULL)
    {
      if (compare_env_dollar(tmp, sh, p) == 0)
	{
	  while (sh->env[p][++l] != '=');
	  memset(sh->cmd[i], 0, strlen(sh->cmd[i]));
	  my_strncpy(sh->cmd[i], sh->env[p], (l + 1));
	}
    }
    free(tmp);
    return (0);
}
