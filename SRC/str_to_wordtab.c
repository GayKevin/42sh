/*
** str_to_wordtab.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 18:18:16 2014 Maxime Limone
** Last update Mon May  5 18:44:15 2014 Maxime Limone
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

char	**malloc_tab(char *str)
{
  int	i;
  int	nb;
  char	**word;

  i = -1;
  nb = 1;
  while (str[++i] != '\0')
    if ((str[i] == ' ' || str[i] == 9) && str[i + 1] > 32)
      ++nb;
  if (str[0] == ' ' || str[0] == 9)
    nb = nb - 1;
  if ((word = malloc(sizeof(char *) * (nb + 3))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb)
    {
      if ((word[i] = malloc(sizeof(char) * (strlen(str) + 6))) == NULL)
	return (NULL);
      memset(word[i], 0, (strlen(str) + 6));
    }
  word[i] = NULL;
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	o;
  char	**word;

  o = 0;
  i = -1;
  j = 0;
  if ((word = malloc_tab(str)) == NULL)
    return (NULL);
  while (str[++i] != '\0')
    {
      while (str[i] == ' ' || str[i] == '\t')
	{
	  o = 0;
	  ++i;
	}
      if (word[j] != NULL)
	{
	  word[j][o++] = str[i];
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    word[j++][o] = '\0';
	}
    }
  return (word);
}
