/*
** cd.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:00:18 2014 Maxime Limone
** Last update Fri May 23 17:56:52 2014 Maxime Limone
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "main.h"
#include "my_errno.h"
#include "pwd.h"
#include "old_pwd.h"

int		cd_home(t_shell *sh, int i)
{
  char		*cd;
  int		l;
  int		o;
  int		p;

  l = -1;
  o = 5;
  p = -1;
  if ((cd = malloc(sizeof(char) * 512)) == NULL)
    return (-1);
  memset(cd, 0, 512);
  while (sh->env[++l] != NULL)
    while (strncmp(sh->env[l], "HOME=", 5) == 0 && sh->env[l][o] != '\0')
	cd[++p] = sh->env[l][o++];
  if (chdir(cd) == -1)
    {
      sh->ok_cmd = -1;
      if (find_errno(sh) == -1)
      	fprintf(stderr, "Error: directory inaccessible\n");
      return (-1);
    }
  old_pwd(sh);
  set_pwd(sh, cd);
  free(cd);
  return (0);
}

int		cd_old_pwd(t_shell *sh, int i)
{
  char		*cmd;
  int		l;
  int		o;
  int		p;

  l = 6;
  o = -1;
  p = 0;
  if ((cmd = malloc(sizeof(char) * 512)) == NULL)
    return (-1);
  memset(cmd, 0, 512);
  while (sh->env[++o] != NULL)
    while (strncmp(sh->env[o], "OLDPWD=", 7) == 0 && sh->env[o][++l] != '\0')
      cmd[p++] = sh->env[o][l];
  if (chdir(cmd) == -1)
    {
      sh->ok_cmd = -1;
      if (find_errno(sh) == -1)
 	fprintf(stderr, "Error: directory inaccessible\n");
      return (-1);
    }
  old_pwd(sh);
  set_pwd(sh, cmd);
  free(cmd);
  return (0);
}

int		find_cd(t_shell *sh, int i)
{
  if (strcmp(sh->cmd[i], "cd") == 0)
    {
      sh->ch = 1;
      if (sh->cmd[i + 1] == NULL)
      	{
      	  if (cd_home(sh, i) == -1)
      	    return (-1);
      	}
      else if (strncmp(sh->cmd[i + 1], "-", 1) == 0)
      	cd_old_pwd(sh, i);
      else
      	{
      	  if (chdir(sh->cmd[i + 1]) == -1)
	    {
	      sh->ok_cmd = -1;
	      if (find_errno(sh) == -1)
		fprintf(stderr, "Error: directory inaccessible\n");
	      return (-1);
	    }
      	  old_pwd(sh);
      	  set_pwd(sh, sh->cmd[i + 1]);
	}
    }
  return (0);
}
