#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int	get_env(t_shell *sh, char **env)
{
  int	i;
  int	l;

  i = -1;
  l = 0;
  if (env != NULL)
    {
      while (env[++i] != NULL)
      	l++;
      if ((sh->env = malloc(sizeof(char *) * (l + 2))) == NULL)
	return (-1);
      i = -1;
      while (env[++i] != NULL)
      	{
      	  sh->env[i] = malloc(sizeof(char) * (strlen(env[i]) + 2));
	  if (sh->env[i] == NULL)
	    return (-1);
	  memset(sh->env[i], 0, (strlen(env[i] + 2)));
      	  strcpy(sh->env[i], env[i]);
	}
      sh->env[i] = NULL;
    }
  return (0);
}
