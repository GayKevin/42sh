/*
** epur_str.c for 42sh in /home/limone_m/rendu/42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Sun May 11 16:41:44 2014 Maxime Limone
** Last update Tue May 13 09:19:52 2014 Kevin Gay
*/

#include <stdlib.h>
#include <string.h>
#include "epur_str.h"

char	*epur_str2(int i, int id, char *dest, char *str)
{
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') &&
        ((str[i + 1] == '\0') || (str[i + 1] == ' ' || str[i + 1] == '\t')))
      i++;
    else if ((str[i] == ' ' || str[i] == '\t') &&
             (str[i + 1] != ' ' && str[i + 1] != '\t'))
      {
	dest[id++] = ' ';
	i++;
      }
    else
      dest[id++] = str[i++];
  return (dest);
}

char		*epur_str(char *str)
{
  int		i;
  int		id;
  char		*dest;
  int		l;

  l = 0;
  i = 0;
  id = 0;
  if ((dest = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  memset(dest, 0, (strlen(str) + 2));
  dest = clean_str(dest, strlen(str));
  dest = epur_str2(i, id, dest, str);
  l = strlen(str);
  memset(str, 0, l);
  strcpy(str, dest);
  free(dest);
  return (str);
}

char		*clean_str(char *str, int size)
{
  int		i;

  i = 0;
  while (i != size)
    str[i++] = '\0';
  return (str);
}
