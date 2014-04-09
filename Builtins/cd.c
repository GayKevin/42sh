#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

int	cd_home(t_shell *sh, int i)
{
  int	l;
  int	o;
  char	*cd;
  int	p;

  p = -1;
  l = -1;
  o = 5;
  cd = malloc(sizeof(char) * 512);
  memset(cd, 0, 512);
  while (sh->env[++l] != NULL)
    if (my_strcmp_nbr(sh->env[l], "HOME=", 5) == 0)
      while (sh->env[l][o] != '\0')
	cd[++p] = sh->env[l][o++];
  if (chdir(cd) == -1)
    return (1);
  old_pwd(sh);
  set_pwd(sh, cd);
  free(cd);
  return (0);
}

int	find_cd(t_shell *sh, int i)
{
  if (my_strcmp(sh->cmd[i], "cd") == 0)
    {
      if (sh->cmd[i + 1] == NULL)
	{
	  if (cd_home(sh, i) == 1)
	    return (1);
	}
      else
	{
	  if(chdir(sh->cmd[i + 1]) == -1)
	    return (1);
	  old_pwd(sh);
	  set_pwd(sh, sh->cmd[i + 1]);
        }
      sh->ch = 1;
    }
  return (0);
 }
