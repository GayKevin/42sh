/*
** pwd.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:18:16 2014 Maxime Limone
** Last update Fri May 16 13:41:32 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "pwd.h"
#include "my_strcat.h"

int		find_pwd_env(t_shell *sh)
{
  int		i;

  i = -1;
  while (sh->env[++i] != NULL)
    {
      if (my_strcmp_("PWD=", sh->env[i]) == 0)
	return (i);
    }
  return (-1);
}

int		create_pwd(t_shell *sh)
{
  int		p;

  p = -1;
  while (sh->env[++p] != NULL);
  if ((sh->env = realloc(sh->env, sizeof(char *) * (p + 2))) == NULL)
    return (-1);
  if (((sh->env)[p] = malloc(sizeof(char) * 1024)) == NULL)
    return (-1);
  memset(sh->env[p], 0, 1024);
  sh->env[p][0] = 'P';
  sh->env[p][1] = 'W';
  sh->env[p][2] = 'D';
  sh->env[p][3] = '=';
  sh->env[p + 1] = NULL;
  return (0);
}

int		set_pwd(t_shell *sh, char *cmd)
{
  char		str[1024];
  int		d;

  d = 0;
  sh->l = 0;
  if ((d = find_pwd_env(sh)) == -1)
    {
      create_pwd(sh);
      set_pwd(sh, cmd);
      return (0);
    }
  sh->l = strlen(sh->env[d]);
  if ((getcwd(str, 1024)) == NULL)
    return (-1);
  memset(sh->env[d], 0, strlen(sh->env[d]));
  sh->env[d][0] = 'P';
  sh->env[d][1] = 'W';
  sh->env[d][2] = 'D';
  sh->env[d][3] = '=';
  my_strcat_1(sh->env[d], str);
  return (0);
}
