/*
** my_getnbr.c for my_getnbr in /home/gay_k/Library
** 
** Made by Kévin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Oct  9 09:14:02 2013 Kévin Gay
** Last update Mon Mar 17 12:05:24 2014 Kevin Gay
*/

int	operator(int signe, char *str)
{
  int	i;

  i = 0;
  while (str[i++] != '\0')
    {
      if (str[i] == '-' && signe != 1)
	{
	  signe = signe + 1;
	}
    }
  return (signe);
}

int	my_getnbr(char *str)
{
  int	i;
  int	fact;
  int	nb;
  int	signe;

  nb = 0;
  i = 0;
  fact = 1;
  signe = 0;
  signe = operator(signe, str);
  i = 0;
  while (str[i++] != '\0')
    {
      if (str[i] <= 57 && str[i] >= 47)
	return (1);
      nb = (nb * fact) + (str[i] - 48);
      fact = fact * 10;
      if (fact >= 100)
	fact = fact / 10;
    }
  if (signe == 1)
    nb = nb * (-1);
  return (nb);
}
