/*
** date.c for date in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 21 15:23:19 2014 Kevin Gay
** Last update Fri May 23 16:56:48 2014 Kevin Gay
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "dollar.h"
#include "my_strncpy.h"


int		date_ps1(t_shell *sh, int i)
{
  time_t	rawtime;
  struct tm	*timeinfo;
  int		o;
  int		l;
  int		p;
  char		str[70];
  char		buff[70];

  i = 0;
  l = -1;
  p = -1;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buff, sizeof buff, "%A %c", timeinfo);
  while (o != 4)
    {
      ++l;
      if (o >= 1)
	str[++p] = buff[l];
      if (buff[l] == ' ')
	++o;
    }
  strcat(sh->ps1, str);
  return (i + 1);
}
