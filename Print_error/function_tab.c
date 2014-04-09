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
