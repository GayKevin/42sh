#include "main.h"
#include "my_put_tool.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  i = my_strlen(dest);
  while (src[k] != '\0')
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat_(char *dest, char *src)
{
  int	i;
  int	k;

  k = 4;
  i = 0;
  i = my_strlen(dest);
  while (src[k] != '\0')
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat_1(char *dest, char *src)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  dest[0] = 'P';
  dest[1] = 'W';
  dest[2] = 'D';
  dest[3] = '=';
  i = my_strlen(dest);
  while (src[k] != '\0')
    {
      if (src[k] == '/' && src[k + 1] == '.')
	return (dest);
      dest[i] = src[k];
      i++;
      k++;
    }
  dest[i] = '\0';
  return (dest);
}
