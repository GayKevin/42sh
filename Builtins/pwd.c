#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "pwd.h"
#include "my_strcat.h"
#include "my_strcmp.h"
#include "my_put_tool.h"

int	find_pwd_env(t_shell *sh)
{
  int	i;

  i = -1;
  while (sh->env[++i] != NULL)
    {
      if (my_strcmp_("PWD=", sh->env[i]) == 0)
	return (i);
    }
  return (-1);
}

int	create_pwd(t_shell *sh)
{
  int	p;
  int	i;

  i = 0;
  p = -1;
  while (sh->env[++p] != NULL);
  if ((sh->env = realloc(sh->env, sizeof(char *) * (p + 2))) == NULL)
    return (-1);
  (sh->env)[p] = malloc(sizeof(char) * 1024);
  if ((sh->env)[p] == NULL)
    return (-1);
  memset(sh->env[p], 0, 1024);
  sh->env[p][0] = 'P';
  sh->env[p][1] = 'W';
  sh->env[p][2] = 'D';
  sh->env[p][3] = '=';
  sh->env[p + 1] = NULL;
  return (0);
}

int	set_pwd(t_shell *sh, char *cmd)
{
  int	d;
  int	i;
  char	*str;

  d = 0;
  i = 0;
  if ((str = malloc(sizeof(char) * 1024)) == NULL)
    return (0);
  memset(str, 0, 512);
  if ((d = find_pwd_env(sh)) == -1)
    {
      create_pwd(sh);
      set_pwd(sh, cmd);
      return (0);
    }
  i = strlen(sh->env[d]) + strlen(cmd);
  sh->l = 0;
  sh->l = my_strlen(sh->env[d]);
  str = getcwd(cmd, 1024);
  memset(sh->env[d], 0, i);
  my_strcat_1(sh->env[d], str);
  return (0);
}
