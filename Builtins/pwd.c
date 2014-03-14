/*
** pwd.c for pwd in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Mar 14 11:00:40 2014 Kevin Gay
** Last update Fri Mar 14 16:58:27 2014 Kevin Gay
*/

#include <stdlib.h>
#include "struct.h"


int	set_pwd_2(int i, int d, t_shell *sh, char *cmd)
{
  if (i > 0)
    if (cmd[i] == '/' && cmd[i - 1] > 47 && cmd[i + 1] > 47)
      find_slash(sh, d, i, cmd);
  if (cmd[0] == '/' && cmd[i + 1] > 47)
    find_first_slash(sh, d, cmd);
  if (cmd[i] == '.' && cmd[i + 1] == '.')
      find_point(sh, d);
  else if (i > 0 && cmd[i] > 47 && cmd[i + 1] == '\0' && sh->j == 0)
    find_slash_2(sh, d, i, cmd);
  else if (cmd[i] > 47 && cmd[i + 2] == '\0' && cmd[i + 1] == '/')
    find_slash_2(sh, d, i, cmd);
  /* else if (cmd[i] == '/' && cmd[i + 1] > 47) */
  /*   { */
  /*     my_putchar('1'); */
  /*   find_first_slash(sh, d, cmd); */
  /*   } */
  else if (cmd[i] == '/' && cmd[i + 1] == '.' && cmd[i + 2] == 46)
    {
      my_putstr("lkjkj");
      find_point(sh, d);
      return (2);
    }
  return (0);
}


int	set_pwd(t_shell *sh, char *cmd)
{
  int	i;
  int	d;

  i = 0;
  d = 0;
  d = find_pwd_env(sh);
  sh->l = 0;
  sh->l = my_strlen(sh->env[d]);
  sh->j = 0;
  while (cmd[i] != '\0')
    {
      if (set_pwd_2(i, d, sh, cmd) == 2)
	i = i + 1;
      my_putstr(sh->env[d]);
      my_putchar('\n');
      ++i;
    }
  return (0);
}
