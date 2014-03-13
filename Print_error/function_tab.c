/*
** function_tab.c for function_tab in /home/gay_k/printf
** 
** Made by Kévin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Nov 15 16:28:11 2013 Kévin Gay
** Last update Mon Mar 10 17:37:59 2014 Kevin Gay
*/

#include <stdarg.h>
#include "flag.h"
#include "struct.h"

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
