#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

char	**clean_str(int nb, char **word, char *str)
{
  int	l;
  int	i;

  l = 0;
  while (l < nb)
    {
      i = 0;
      while (i != (my_strlen(str) + 5))
	{
	  word[l][i] = '\0';
	  ++i;
	}
      ++l;
    }
  return (word);
}

char	**malloc_tab(char *str)
{
  int	i;
  int	nb;
  char	**word;

  i = 0;
  nb = 1;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == 9) && str[i + 1] > 32)
	++nb;
      ++i;
    }
  if (str[0] == ' ' || str[0] == 9)
    nb = nb - 1;
  if ((word = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb)
    word[i] = malloc(sizeof(char) * my_strlen(str) + 6);
  word[i] = NULL;
  word = clean_str(nb, word, str);
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	o;
  char	**word;

  o = 0;
  i = 0;
  j = 0;
  if ((word = malloc_tab(str)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      while (str[i] == ' ' || str[i] == 9)
	{
	  o = 0;
	  ++i;
	}
      if (word[j] != NULL)
	{
	  word[j][o++] = str[i];
	  if (str[i + 1] == ' ' || str[i + 1] == 9)
	    word[j++][o] = '\0';
	}
      ++i;
    }
  return (word);
}
