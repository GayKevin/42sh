/*
** my_put_error.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Print_error
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 15:01:05 2014 Maxime Limone
** Last update Mon May  5 15:01:31 2014 Maxime Limone
*/

#include <unistd.h>

void	my_puterror(char c)
{
  write(2, &c, 1);
}

void	my_putstr_e(char *str)
{
  int	number;

  number = 0;
  while (str[number] != '\0')
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
