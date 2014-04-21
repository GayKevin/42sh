#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "find_pwd.h"
#include "my_strcmp.h"
#include "my_malloc_pwd.h"
#include "my_strcpy.h"
#include "my_strcat.h"
#include "my_put_tool.h"

int	find_pwd_env(t_shell *sh)
{
  int	i;

  i = 0;
  while (sh->env[i] != NULL)
    {
      if (my_strcmp_("PWD=", sh->env[i]) == 0)
	return (i);
      ++i;
    }
  return (0);
}

void	find_point(t_shell *sh, int d)
{
  sh->l = my_strlen(sh->env[d]);
  while (sh->env[d][sh->l] != '/')
    sh->l--;
  if (sh->l == 4)
    sh->env[d][sh->l++] = '/';
  sh->env[d][sh->l] = '\0';
}

void	find_slash(t_shell *sh, int d, int i, char *cmd)
{
  my_malloc_pwd(sh, d, cmd);
  while ((i > 0) && (cmd[i] != '/' ))
    i--;
  sh->en[sh->l++] = '/';
  i--;
  if (i > 0 && cmd[i] == '.' && cmd[i - 1] == '.')
    i = i + 2;
  else
    while ((i > 0) && (cmd[i] != '/'))
      i--;
  if (i < 0)
    i = 0;
  while ((cmd[i] != '/') && (cmd[i] != '\0'))
    {
      sh->en[sh->l] = cmd[i++];
      sh->l = sh->l + 1;
    }
  sh->en[sh->l] = '\0';
  my_strcpy(sh->env[d], sh->en);
  free(sh->en);
}

int	find_slash_2(t_shell *sh, int d, int i, char *cmd)
{
  if (cmd[0] == '/')
    return (0);
  my_malloc_pwd(sh, d, cmd);
  while ((i > 0) && (cmd[i] != '/'))
    i--;
  sh->en[sh->l++] = '/';
  if (i != 0)
    i++;
  if (i > 0)
    if (cmd[i - 1] == '.')
      ++i;
  while ((cmd[i] != '/') && (cmd[i] != '\0'))
    {
      sh->en[sh->l] = cmd[i];
      ++i;
      sh->l = sh->l + 1;
    }
  sh->en[sh->l] = '\0';
  my_strcpy(sh->env[d], sh->en);
  free(sh->en);
  return (0);
}

int	find_first_slash(t_shell *sh, int d, char *cmd)
{
  char	*env;
  int	i;

  i = strlen(sh->env[d]) + strlen(cmd);
  sh->l = 0;
  if ((env = malloc(sizeof(char) * i)) == NULL)
    return (1);
  memset(env, 0, i);
  free(sh->env[d]);
  if ((sh->env[d] = malloc(sizeof(char) * i)) == NULL)
    return (1);
  memset(sh->env[d], 0, i);
  my_strcat_1(env, cmd);
  strcpy(sh->env[d], env);
  sh->j = 1;
  free(env);
  return (0);
}
