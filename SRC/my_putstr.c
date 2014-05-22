/*
** my_putstr.c for my_putstr in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 14:34:50 2014 Kevin Gay
** Last update Mon May 19 12:14:02 2014 Maxime Limone
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    write(1, &str[i], 1);
}

char		*my_strcut_char(char *str, char cut)
{
  int		i;
  char		*new_str;

  i = -1;
  if ((new_str = malloc(sizeof(char) * strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[++i] != cut && str[i] != '\0')
    new_str[i] = str[i];
  return (new_str);
}
