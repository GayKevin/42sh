/*
** clean_str.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:21:36 2014 Maxime Limone
** Last update Mon May  5 15:21:37 2014 Maxime Limone
*/

#include "main.h"

void	clear_str(t_shell *sh)
{
  int	i;

  i = -1;
  while (++i != 512)
    sh->buffer[i] = '\0';
}
