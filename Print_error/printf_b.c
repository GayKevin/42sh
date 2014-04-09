#include "struct.h"
#include "flag.h"

void	printf_b(unsigned int nbr)
{
  my_putnbr_base(nbr, "01");
}

void	printf_s(char *str)
{
  int	i;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 32 || str[i] >= 127)
	{
	  my_putchar(92);
	  if (str[i] < 64)
	    {
	      my_putchar('0');
	    }
	  if (str[i] < 8)
	    {
	      my_putchar('0');
	    }
	  my_putnbr_base(str[i], "01234567");
	}
      else
	{
	  my_putchar(str[i]);
	}
      i = i + 1;
    }
}
