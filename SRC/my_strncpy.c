/*
** my_strncpy.c for strncpy in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 11:37:49 2014 Kevin Gay
** Last update Wed May 14 02:16:46 2014 Kevin Gay
*/

char    *my_strncpy(char *dest, char *src, int i)
{
  int	t;

  t = -1;
  while (src[i] != '\0')
    dest[++t] = src[i++];
  dest[++t] = '\0';
  return (dest);
}
