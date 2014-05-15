/*
** function_tab.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Print_error
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 14:58:10 2014 Maxime Limone
** Last update Mon May  5 14:58:11 2014 Maxime Limone
*/

#include <stdarg.h>
#include "flag.h"

void	numbers(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_put_nbr_e(nb);
}

void	sentence(va_list list)
{
  char	*str;

  str  = va_arg(list, char *);
  my_putstr_e(str);
}

void	character(va_list list)
{
  int	c;

  c = va_arg(list, int);
  my_puterror(c);
}

void	modulo()
{
  my_puterror('%');
}
