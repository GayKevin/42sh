/*
** pwd.c for pwd in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Mar 14 11:00:40 2014 Kevin Gay
** Last update Sat Mar 15 16:11:07 2014 Kevin Gay
*/

#include <stdlib.h>
#include "struct.h"

int	set_pwd_2(int i, int d, t_shell *sh, char *cmd)
{
  if (cmd[i] == '.' && cmd[i + 1] == '.')
    find_point(sh, d);
  else if (cmd[0] == '/' && cmd[i + 1] > 47)
    find_first_slash(sh, d, cmd);
  else if (cmd[i] > 47 && cmd[i + 2] == '\0' && cmd[i + 1] == '/')
    find_slash_2(sh, d, i, cmd);
  else if (i > 0 && cmd[i] > 47 && cmd[i + 1] == '/' && cmd[i + 2] == '.')
    find_slash_2(sh, d, i, cmd);
  else if (i > 0 && cmd[i] > 47 && cmd[i + 1] == '\0' && sh->j == 0)
    find_slash_2(sh, d, i, cmd);
  else if (i > 0 && cmd[i] == '/' && cmd[i + 1] > 47 && cmd[i - 1] > 47)
      find_slash(sh, d, i, cmd);
  else if (cmd[i] == '/' && cmd[i + 1] == '.' && cmd[i + 2] == 46)
    {
      find_point(sh, d);
      return (2);
    }
  return (0);
}


int	set_pwd(t_shell *sh, char *cmd)
{
  int	i;
  int	d;

  i = -1;
  d = 0;
  d = find_pwd_env(sh);
  sh->l = 0;
  sh->l = my_strlen(sh->env[d]);
  while (cmd[++i] != '\0')
    {
      sh->j = 0;
      if (set_pwd_2(i, d, sh, cmd) == 2)
	++i;
    }  return (0);
}