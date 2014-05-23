/*
** shell.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 16:09:34 2014 Maxime Limone
** Last update Fri May 23 18:29:35 2014 Kevin Gay
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "path.h"
#include "my_free.h"
#include "clean_str.h"
#include "str_to_wordtab.h"
#include "my_strcat.h"
#include "built_in.h"
#include "execve.h"
#include "dollar.h"
#include "pars.h"
#include "tree.h"
#include "my_putstr.h"
#include "epur_str.h"
#include "ps1.h"

int		read_buffer(t_shell *sh)
{
  int		ret;

  find_ps1(sh);
  my_putstr(sh->ps1);
  free(sh->ps1);
  free(sh->ps_1);
  clear_str(sh);
  while ((ret = read(0, sh->buffer, 512)) == 512);
  if (ret == 0)
    {
      putchar(10);
      return (0);
    }
  sh->buffer[ret - 1] = '\0';
  return (ret);
}

void		number_reset(t_shell *sh)
{
  sh->ch = 0;
  sh->c_ch = 0;
  sh->ok_cmd = 0;
}

int		shell(t_shell *sh)
{
  int		r;

  while (42)
    {
      sh->i_tree = -1;
      sh->check = 0;
      if (find_path(sh) == -1)
	return (-1);
      if ((r = read_buffer(sh)) > 1)
	{
	  if (parsing_main(epur_str(sh->buffer), sh) == -1)
	    return (-1);
	}
      else if (r == 0)
	return (-1);
      my_free(sh->path);
    }
  return (0);
}

int		check_cmd(t_shell *sh, t_node *tree)
{
  int		i;

  i = -1;
  number_reset(sh);
  sh->cmd = my_str_to_wordtab(tree->str);
  dollar(sh);
  check_point_slash(sh, sh->env);
  if (built_in(sh) == -1)
    return (-1);
  while (sh->path != NULL && sh->path[++i] != NULL && sh->ch == 0)
    if (access(strcat(sh->path[i], sh->cmd[0]), X_OK) == 0)
      exec_cmd(sh->path[i], sh->cmd, sh->env, sh);
  if (sh->ch == 0)
    exec_slah_bin(sh->cmd, sh);
  if (sh->ch == 0)
    {
      fprintf(stderr, "Error: '%s' command not found\n", sh->cmd[0]);
      sh->ok_cmd = -1;
      return (0);
    }
  my_free(sh->cmd);
  return (0);
}
