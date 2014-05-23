/*
** get_stuff.c for get_stuff in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri May 23 18:09:15 2014 Kevin Gay
** Last update Fri May 23 18:23:25 2014 Kevin Gay
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "my_strncpy.h"
#include "my_strcmp.h"

int		get_half_hostname_ps1(t_shell *sh, int i)
{
  char		str[512];
  char		str1[512];
  int		o;

  o = -1;
  ++i;
  memset(str, 0, 512);
  memset(str1, 0, 512);
  gethostname(str, 512);
  while (str[++o] != '.')
    str1[o] = str[o];
  strcat(sh->ps1, str1);
  return (i + 1);
}

int		get_username_ps1(t_shell *sh, int i)
{
  char		str[512];

  ++i;
  memset(str, 0, 512);
  getlogin_r(str, 512);
  strcat(sh->ps1, str);
  return (i + 1);
}

int		get_nbr(t_shell *sh, int i)
{
  static int	l;
  char		str[10];


  memset(str, 0, 10);
  sprintf(str, "%d", l);
  ++l;
  i = i + 2;
  strcat(sh->ps1, str);
  return (i);
}

int		get_full_hostname_ps1(t_shell *sh, int i)
{
  char		str[512];

  ++i;
  memset(str, 0, 512);
  gethostname(str, 512);
  strcat(sh->ps1, str);
  return (i + 1);
}


int		get_print_letter(t_shell *sh, int i)
{
  char	str[2];

  str[0] = sh->ps_1[i++];
  str[1] = '\0';
  strcat(sh->ps1, str);
  return (i - 1);
}
