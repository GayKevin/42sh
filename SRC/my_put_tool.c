#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	number;

  number = 0;
  while (str[number] != '\0')
    {
      my_putchar(str[number]);
      number =  number + 1;
    }
}

void	my_put_nbr(int nb)
{
  int	result;

  result = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb ;
    }
  if (nb  > 9)
    my_put_nbr(nb / 10);
  if (result == 1)
    {
      result = 0;
      my_putchar(nb % 10 + 49);
    }
  else
    my_putchar(nb % 10 + 48);
}

int     my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
