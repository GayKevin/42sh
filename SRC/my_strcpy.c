/*
** my_strcpy.c for strcpy in /home/gay_k/rendu/PSU/PSU_2013_minishell1
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Mar  7 12:55:20 2014 Kevin Gay
** Last update Thu Mar 13 12:20:14 2014 Kevin Gay
*/

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = -1;
  while (src[++i] != '\0')
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
