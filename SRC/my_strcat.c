/*
** my_strcat.c for strcat in /home/gay_k/rendu/CPE-2013-BSQ
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Dec  4 11:30:05 2013 Kevin Gay
** Last update Fri Mar 14 13:11:20 2014 Kevin Gay
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

/* char	*my_strcat_(char *dest, char *src, t_path *pa) */
/* { */
/*   int	i; */
/*   int	k; */

/*   k = 4; */
/*   i = 0; */
/*   i = my_strlen(dest); */
/*   while (src[k] != '\0') */
/*     { */
/*       dest[i] = src[k]; */
/*       i++; */
/*       k++; */
/*     } */
/*   dest[i] = '\0'; */
/*   return (dest); */
/* } */

char	*my_strcat_1(char *dest, char *src)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  dest[0] = 'P';
  dest[1] = 'W';
  dest[2] = 'D';
  dest[3] = '=';
  i = my_strlen(dest);
  while (src[k] != '\0')
    {
      if (src[k] == '/' && src[k + 1] == '.')
	return (dest);
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}
