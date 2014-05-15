/*
** old_pwd.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 18:23:40 2014 Maxime Limone
** Last update Thu May 15 18:06:25 2014 Maxime Limone
*/

#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "old_pwd.h"
#include "pwd.h"
#include "my_strcat.h"

int		find_old_pwd_env(t_shell *sh)
{
  int		i;

  i = -1;
  while (sh->env[++i] != '\0')
    if (my_strcmp_("OLDPWD=", sh->env[i]) == 0)
      return (i);
  return (-1);
}

char		*clear_old_pwd(char *str, int d, t_shell *sh)
{
  int		i;

  i = 0;
  while (i != strlen(sh->env[d]) * 2)
    {
      str[i] = '\0';
      ++i;
    }
  return (str);
}

int		old_pwd(t_shell *sh)
{
  int		d;
  int		l;

  l = 0;
  d = 0;
  if ((d = find_pwd_env(sh)) == -1)
    return (-1);
  if ((l = find_old_pwd_env(sh)) == -1)
    l = l - 1;
  free(sh->env[l]);
  sh->env[l] = malloc(sizeof(char) * (strlen(sh->env[d])  * 2));
  if (sh->env[l] == NULL)
    return (-1);
  sh->env[l] = clear_old_pwd(sh->env[l], d , sh);
  sh->env[l][0] = 'O';
  sh->env[l][1] = 'L';
  sh->env[l][2] = 'D';
  sh->env[l][3] = 'P';
  sh->env[l][4] = 'W';
  sh->env[l][5] = 'D';
  sh->env[l][6] = '=';
  my_strcat_(sh->env[l], sh->env[d]);
  return (0);
}
