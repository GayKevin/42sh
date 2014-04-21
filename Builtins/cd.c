#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "my_strcmp.h"
#include "pwd.h"
#include "old_pwd.h"

int	cd_home(t_shell *sh, int i)
{
  int	l;
  int	o;
  char	*cd;
  int	p;

  p = -1;
  l = -1;
  o = 5;
  if ((cd = malloc(sizeof(char) * 512)) == NULL)
    return (1);
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

int	cd_old_pwd(t_shell *sh, int i)
{
  int	o;
  int	l;
  int	p;
  char	*cmd;

  l = 6;
  o = -1;
  p = 0;
  cmd = malloc(sizeof(char) * 512);
  memset(cmd, 0, 512);
  while (sh->env[++o] != NULL)
    {
      if (my_strcmp_nbr(sh->env[o], "OLDPWD=", 7) == 0)
	{
	  while (sh->env[o][++l] != '\0')
	    cmd[p++] = sh->env[o][l];
	}
    }
  if (chdir(cmd) == -1)
    return (1);
  old_pwd(sh);
  set_pwd(sh, cmd);
  free(cmd);
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
      else if (my_strcmp_nbr(sh->cmd[i + 1], "-", 1) == 0)
	cd_old_pwd(sh, i);
      else
      	{
	  if (chdir(sh->cmd[i + 1]) == -1)
      	    return (1);
      	  old_pwd(sh);
      	  set_pwd(sh, sh->cmd[i + 1]);
        }
      sh->ch = 1;
    }
  return (0);
 }
