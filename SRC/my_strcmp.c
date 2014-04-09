#include "struct.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '\0')
      i++;
  if (str1[i] != str2[i])
    return (1);
  return (0);
}

int	my_strcmp_(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '=')
    i++;
  if (str1[i] == '=' && str2[i] == '=')
    return (0);
  if (str1[i] != str2[i])
    return (1);
  return (0);
}

int	my_strcmp_nbr(char *str1, char *str2, int o)
{
  int	i;

  i = -1;
  while (++i != o)
    if (str1[i] != str2[i])
      return (1);
  return (0);
}
