/*
** my_strcat.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 17:36:58 2014 Maxime Limone
** Last update Mon May  5 19:43:52 2014 Maxime Limone
*/

#include <unistd.h>
#include <string.h>
#include "main.h"

void		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    write(1, &str[i], 1);
}

char		*my_strcat_(char *dest, char *src)
{
  int		i;
  int		k;

  k = 4;
  i = 0;
  i = strlen(dest);
  while (src[k] != '\0')
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strcat_1(char *dest, char *src)
{
  int		i;
  int		k;

  k = 0;
  i = 0;
  dest[0] = 'P';
  dest[1] = 'W';
  dest[2] = 'D';
  dest[3] = '=';
  i = strlen(dest);
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

char		*my_strcat_slash(char *dest, char *src)
{
  int		i;
  int		k;

  k = 2;
  i = 0;
  i = strlen(dest);
  dest[i] = '/';
  i++;
  while (src[k] != '\0')
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}

int		my_strcmp_(char *str1, char *str2)
{
  int		i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '=')
    i++;
  if (str1[i] == '=' && str2[i] == '=')
    return (0);
  if (str1[i] != str2[i])
    return (1);
  return (0);
}
