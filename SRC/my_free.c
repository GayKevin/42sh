/*
** my_free.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 16:16:11 2014 Maxime Limone
** Last update Wed May 14 11:29:38 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>

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
