/*
** my_show_tab.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 17:35:02 2014 Maxime Limone
** Last update Mon May  5 17:36:34 2014 Maxime Limone
*/

#include <stdlib.h>
#include <stdio.h>

void    my_show_tab(char **tab)
{
  int    i;

  i = -1;
  while (tab[++i] != NULL)
    printf("%s\n", tab[i]);
}
