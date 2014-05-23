/*
** ascii.c for ascii in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 21 15:24:02 2014 Kevin Gay
** Last update Fri May 23 17:41:50 2014 Kevin Gay
*/

#include <string.h>
#include "main.h"

void	strcat_nbr(char *dest, char *src, int i)
{
  int	p;

  p = -1;
  while (dest[++p] != '\0');
  while (src[i] != '\0')
    dest[p++] = src[i++];
  dest[p] = '\0';
}

int	ascii_ps1(t_shell *sh, int i)
{
  char	str[50];
  char	str2[50];
  int	l;

  l = -1;
  while (sh->ps_1[i - 1] != 'm' && sh->ps_1[i] != '\0')
    str[++l] = sh->ps_1[i++];
  str[++l] = '\0';
  l = -1;
  str2[0] = '\e';
  str2[1] = '\0';
  l = -1;
  while (str[++l] != '[');
  strcat_nbr(str2, str, l);
  strcat(sh->ps1, str2);
  return (i);
}
