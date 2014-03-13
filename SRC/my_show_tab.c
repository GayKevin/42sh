/*
** my_show_tab.c for show tab$ in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Mon Mar 10 17:40:40 2014 Kevin Gay
** Last update Thu Mar 13 13:50:29 2014 Kevin Gay
*/

#include <stdlib.h>
#include "struct.h"


void    my_show_tab(char **tab)
{
  int    i;

  i = -1;
  while (tab[++i] != NULL)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
    }
}
