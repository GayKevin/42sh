/*
** my_strcat.c for strcat in /home/gay_k/rendu/CPE-2013-BSQ
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Dec  4 11:30:05 2013 Kevin Gay
** Last update Thu Mar 13 00:04:54 2014 Kevin Gay
*/

#include "struct.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  i = my_strlen(dest);
  while (src[k] != '\0')
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}
