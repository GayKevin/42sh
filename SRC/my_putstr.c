/*
** my_putstr.c for my_putstr in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 14:34:50 2014 Kevin Gay
** Last update Tue May 13 14:35:23 2014 Kevin Gay
*/

#include <unistd.h>

void		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    write(1, &str[i], 1);
}
