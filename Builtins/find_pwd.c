/*
** find_pwd.c<2> for find_pwd in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Mar 14 11:08:01 2014 Kevin Gay
** Last update Fri Mar 14 16:08:01 2014 Kevin Gay
*/

#include <string.h>
#include <stdlib.h>
#include "struct.h"

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
  char	*ev;

  sh->l = my_strlen(sh->env[d]);
  ev = malloc(sizeof(char) * (strlen(sh->env[d]) + strlen(cmd) + 2));
  memset(ev, 0, (strlen(sh->env[d]) + strlen(cmd) + 2));
  my_strcpy(ev, sh->env[d]);
  free(sh->env[d]);
  sh->env[d] = malloc(sizeof(char) * (strlen(ev)) + 10);
  memset(sh->env[d], 0, strlen(ev) + 10);
  while ((i > 0) && (cmd[i] != '/' ))
    i--;
  ev[sh->l++] = '/';
  i--;
  if (cmd[i] == '.' && cmd[i - 1] == '.')
    i = i + 2;
  else
    while ((i > 0) && (cmd[i] != '/'))
      i--;
  if (i < 0)
    i = 0;
  while ((cmd[i] != '/') && (cmd[i] != '\0'))
    {
      ev[sh->l] = cmd[i++];
      sh->l = sh->l + 1;
    }
  ev[sh->l] = '\0';
  my_strcpy(sh->env[d], ev);
  free(ev);
}

void	find_slash_2(t_shell *sh, int d, int i, char *cmd)
{
  char	*en;

  sh->l = my_strlen(sh->env[d]);
  en = malloc(sizeof(char) * (strlen(sh->env[d]) + strlen(cmd) + 2));
  memset(en, 0, (strlen(sh->env[d]) + strlen(cmd) + 2));
  my_strcpy(en, sh->env[d]);
  free(sh->env[d]);
  sh->env[d] = malloc(sizeof(char) * (strlen(en)) + 10);
  memset(sh->env[d], 0, strlen(en) + 10);
  while ((i > 0) && (cmd[i] != '/'))
    i--;
  en[sh->l++] = '/';
  if (i > 0)
    if (sh->cmd[i - 1] == '.')
      ++i;
  while ((cmd[i] != '/') && (cmd[i] != '\0'))
    {
      en[sh->l] = cmd[i];
      ++i;
      sh->l = sh->l + 1;
    }
  en[sh->l] = '\0';
  my_strcpy(sh->env[d], en);
  free(en);
}

void	find_first_slash(t_shell *sh, int d, char *cmd)
{
  char	*env;
  int	i;

  my_putchar('1');
  i = strlen(sh->env[d]) + strlen(cmd);
  sh->l = 0;
  env = malloc(sizeof(char) * i);
  memset(env, 0, i);
  free(sh->env[d]);
  sh->env[d] = malloc(sizeof(char) * i);
  memset(sh->env[d], 0, i);
  my_strcat_1(env, cmd);
  strcpy(sh->env[d], env);
  sh->j = 1;
  free(env);
}
