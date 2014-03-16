/*
** my_free.c for my_free in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue Mar 11 14:02:29 2014 Kevin Gay
** Last update Fri Mar 14 13:55:30 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void	my_free(char **str)
{
  int	i;

  i = -1;
  if (str)
    {
      while (str[++i] != NULL)
	free(str[i]);
      free(str);
    }
}
