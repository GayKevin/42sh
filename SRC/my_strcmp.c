#include "main.h"
#include "env.h"
#include "my_free.h"
#include "shell.h"

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
