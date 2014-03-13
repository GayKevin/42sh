/*
** main.c for Printf in /home/gay_k/printf
**
** Made by Kévin Gay
** Login   <gay_k@epitech.net>
**
** Started on  Wed Nov  6 20:56:27 2013 Kévin Gay
** Last update Mon Mar 10 12:55:54 2014 Kevin Gay
*/

#include <stdarg.h>
#include <stdlib.h>
#include "flag.h"
#include "struct.h"


char	*tab(char *tab)
{
  tab = malloc(sizeof(char) * 5);
  if (tab == NULL)
    return (NULL);
  tab[0] = 'd';
  tab[1] = 's';
  tab[2] = 'c';
  tab[3] = '%';
  tab[4] = 'i';
  return(tab);
}

flag	*tab_function(flag *tab_function)
{
  tab_function = malloc(sizeof(flag) * 5);
  if (tab_function == NULL)
    return (NULL);
  tab_function[0] = numbers;
  tab_function[1] = sentence;
  tab_function[2] = character;
  tab_function[3] = modulo;
  tab_function[4] = numbers;
  return(tab_function);
}

void	compare(va_list ap, const  char *format, flag *tab_func, char *tab_tab)
{
  int	i;
  int	o;

  i = -1;
  o = 0;
  while (format[++i] != '\0')
    {
      if (format[i] == '%')
	{
	  ++i;
	  while (tab_tab[o] != format[i])
	    ++o;
	  tab_func[o](ap);
	}
      else if (format[i] != '%')
	my_puterror(format[i]);
      o = 0;
    }
}

/* void	free_printf(char *str, int nb) */
/* { */
/*   int	i; */

/*   i = -1; */
/*   while (++i != nb) */
/*     free(str[i]); */
/*   free(str); */
/* } */

int	printf_error(const char *format, ...)
{
  va_list	ap;
  flag		*tab_func;
  char		*tab_tab;

  tab_func = NULL;
  tab_tab = NULL;
  va_start(ap, format);
  tab_tab = tab(tab_tab);
  tab_func = tab_function(tab_func);
  compare(ap, format, tab_func, tab_tab);
  //free_printf(tab_tab, 5);
  //free_printf(tab_func, 5);
  free(tab_tab);
  free(tab_func);
  va_end(ap);
  return (0);
}
