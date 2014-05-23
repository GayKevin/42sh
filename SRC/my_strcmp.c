/*
** my_strcmp.c for strcmp in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 21 12:04:01 2014 Kevin Gay
** Last update Fri May 23 19:47:59 2014 Maxime Limone
*/

int	my_strncmp_nbr(char *str1, char *str2, int o, int i)
{
  int	p;

  p = 0;
  while (i != (o + 1))
    {
      if (str1[i] != str2[p])
	return (1);
      ++p;
      ++i;
    }
  return (0);
}
