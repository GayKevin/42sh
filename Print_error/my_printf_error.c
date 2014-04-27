#include <stdarg.h>
#include <stdlib.h>
#include "flag.h"


char	*tab(char *tab)
{
  if ((tab = malloc(sizeof(char) * 5)) == NULL)
    return (NULL);
  tab[0] = 'd';
  tab[1] = 's';
  tab[2] = 'c';
  tab[3] = '%';
  tab[4] = 'i';
  return (tab);
}

flag	*tab_function(flag *tab_function)
{
  if ((tab_function = malloc(sizeof(flag) * 5)) == NULL)
    return (NULL);
  tab_function[0] = numbers;
  tab_function[1] = sentence;
  tab_function[2] = character;
  tab_function[3] = modulo;
  tab_function[4] = numbers;
  return (tab_function);
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
  free(tab_tab);
  free(tab_func);
  va_end(ap);
  return (0);
}
