/*
** my_putchar.c for my_putchar in /home/gay_k/rendu/Piscine-C-lib/my
** 
** Made by Kévin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Oct  9 09:43:19 2013 Kévin Gay
** Last update Wed Mar 12 23:41:26 2014 Kevin Gay
*/

#include <unistd.h>

void	my_puterror(int c)
{
  write(2, &c, 1);
}

void	my_putstr_e(char *str)
{
  int	number;

  number = 0;
  while(str[number] != '\0')
    {
      my_puterror(str[number]);
      number =  number + 1;
    }
}

void     my_put_nbr_e(int nb)
{
  int   result;

  result = 0;
  if (nb < 0)
    {
      my_puterror('-');
      nb = - nb ;
    }
  if (nb  > 9)
    my_put_nbr_e(nb / 10);
  if (result == 1)
    {
      result = 0;
      my_puterror(nb % 10 + 49);
    }
  else
    my_puterror(nb % 10 + 48);
}
