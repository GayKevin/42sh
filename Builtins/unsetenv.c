#include <stdlib.h>
#include "struct.h"

int	my_strcmp_unsetenv(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '=')
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  return (0);
}

int	find_unset_env(t_shell *sh ,int l, int i)
{
  if (my_strcmp_unsetenv(sh->cmd[i + 1], sh->env[l]) == 0)
    return (0);
  return (1);
}

int	unset_env(t_shell *sh, int i)
{
  int	l;

  l = -1;
  if (my_strcmp_nbr(sh->cmd[i + 1], "PATH", 4) == 0)
    {
      my_free(sh->path);
      sh->path = NULL;
    }
  while (sh->env[++l] != '\0')
    {
      if (find_unset_env(sh, l, i) == 0)
	{
	  free(sh->env[l]);
	  while (sh->env[l] != '\0')
	  {
	    sh->env[l] = sh->env[l + 1];
	    l++;
	  }
	}
      if (sh->env[l] == '\0')
	return (0);
    }
  return (0);
}
