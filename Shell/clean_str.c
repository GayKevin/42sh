/*
** clean_str.c for clean_str in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Mon Mar 10 16:01:54 2014 Kevin Gay
** Last update Mon Mar 10 16:32:03 2014 Kevin Gay
*/

 #include "struct.h"

void	clear_str(t_shell *sh)
{
  int	i;

  i = -1;
  while (++i != 512)
    sh->buffer[i] = '\0';
}
