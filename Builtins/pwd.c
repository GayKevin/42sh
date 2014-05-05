/*
** pwd.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:18:16 2014 Maxime Limone
** Last update Mon May  5 13:15:31 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "pwd.h"
#include "my_strcat.h"
#include "my_strcmp.h"
#include "my_put_tool.h"

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
  int		i;
  int		p;

  i = 0;
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
  char		*str;
  int		d;
  int		i;

  d = 0;
  i = 0;
  if ((d = find_pwd_env(sh)) == -1)
    {
      create_pwd(sh);
      set_pwd(sh, cmd);
      return (0);
    }
  i = strlen(sh->env[d]) + strlen(cmd);
  sh->l = 0;
  sh->l = my_strlen(sh->env[d]);
  if ((str = getcwd(cmd, 1024)) == NULL)
    return (-1);
  memset(sh->env[d], 0, i);
  my_strcat_1(sh->env[d], str);
  return (0);
}
