/*
** old_pwd.c<2> for old in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Sun Mar 16 05:24:16 2014 Kevin Gay
** Last update Sun Mar 16 05:48:00 2014 Kevin Gay
*/

#include <stdlib.h>
#include "struct.h"

int	find_old_pwd_env(t_shell *sh)
{
  int	i;

  i = 0;
  while (sh->env[i] != '\0')
    {
      if (my_strcmp_("OLDPWD=", sh->env[i]) == 0)
	return (i);
      ++i;
    }
  return (i);
}

int	find_old_pwd_env_1(t_shell *sh)
{
  int	i;

  i = 0;
  while (sh->env[i] != '\0')
    {
      if (my_strcmp_("OLDPWD=", sh->env[i]) == 0)
	return (0);
      ++i;
    }
  return (1);
}

char	*clear_old_pwd(char *str, int d, t_shell *sh)
{
  int	i;

  i = 0;
  while (i != my_strlen(sh->env[d]) * 2)
    {
      str[i] = '\0';
      ++i;
    }
  return (str);
}

int	old_pwd(t_shell *sh)
{
  int	d;
  int	l;

  l = 0;
  d = 0;
  d = find_pwd_env(sh);
  l = find_old_pwd_env(sh);
  if (find_old_pwd_env_1(sh) == 1)
    l = l - 1;
  my_put_nbr(l);
  free(sh->env[l]);
  sh->env[l] = malloc(sizeof(char) * my_strlen(sh->env[d])  * 2);
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
