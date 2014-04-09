#include <unistd.h>
#include "struct.h"

int	built_in(t_shell *sh)
{
  int	i;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      if (find_cd(sh, i) == 1)
	return (0);
      if (my_strcmp_nbr(sh->cmd[i], "exit", 4) == 0)
	{
	  if (sh->cmd[i + 1] != NULL)
	    sh->re = my_getnbr(sh->cmd[i + 1]);
	  my_free(sh->cmd);
	  return (1);
	}
      if (find_env(sh, i) == 1)
	return (0);
      if (find_unsetenv(sh, i) == 1)
	return (0);
      if (find_setenv(sh, i) == 1)
	return (0);
    }
  return (0);
}
