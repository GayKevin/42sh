/*
** unsetenv.c for unsetenv in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Mar 12 17:17:25 2014 Kevin Gay
** Last update Wed Mar 12 23:49:43 2014 Kevin Gay
*/

#include "struct.h"

int	my_strcmp_unsetenv(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '=')
    i++;
  if (str1[i] == '=' && str2[i] == '=')
    return (0);
  if (str1[i] != str2[i])
    return (1);
  return (0);
}

int	find_unset_env(t_shell *sh ,int l, int i)
{
  if (my_strcmp_unsetenv(sh->cmd[i + 1], sh->env[l]) == 0)
    return (0);
  return (1);
}

int	unset_env(t_shell *sh, int i)
{
  int	l;

  l = -1;
  while (sh->env[++l] != '\0')
    {
      if (find_unset_env(sh, l, i) == 0)
	while (sh->env[l] != '\0')
	  {
	    sh->env[l] = sh->env[l + 1];
	    l++;
	  }
      if (sh->env[l] == '\0')
	return (0);
    }
  return (0);
}
