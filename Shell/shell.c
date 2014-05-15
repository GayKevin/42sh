/*
** shell.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 16:09:34 2014 Maxime Limone
** Last update Thu May 15 13:59:21 2014 Kevin Gay
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
#include "ps1.h"

int		read_buffer(t_shell *sh)
{
  int		ret;

  //  find_ps1(sh);
  find_ps1(sh);
  my_putstr("$> ");
  clear_str(sh);
  while ((ret = read(0, sh->buffer, 512)) == 512);
  if (ret == 1 || ret == -1)
    {
      read_buffer(sh);
      return (0);
    }
  if (ret == 0)
    {
      putchar(10);
      return (-1);
    }
  sh->buffer[ret - 1] = '\0';
  return (0);
}

int		shell(t_shell *sh)
{
  while (42)
    {
      sh->ok_cmd = 0;
      sh->i_tree = -1;
      sh->check_l = 0;
      if (find_path(sh) == -1)
	return (-1);
      if (read_buffer(sh) == -1)
	return (-1);
      if (init_op_tab(sh->buffer, sh) == -1)
	return (-1);
      my_free(sh->path);
    }
  return (0);
}

int		check_cmd(t_shell *sh, t_node *tree)
{
  int		i;

  i = 0;
  sh->ch = 0;
  sh->c_ch = 0;
  sh->cmd = my_str_to_wordtab(tree->str);
  dollar(sh);
  check_point_slash(sh, sh->env);
  if (built_in(sh) == -1)
    return (-1);
  while (sh->path != NULL && sh->path[i] != NULL && sh->ch == 0)
    if (access(strcat(sh->path[i++], sh->cmd[0]), X_OK) == 0)
      exec_cmd(sh->path[i - 1], sh->cmd, sh->env, sh);
  if (sh->ch == 0)
    exec_slah_bin(sh->cmd, sh);
  sh->ch == 0 ? printf("Command not found\n") : 0;
  my_free(sh->cmd);
  return (0);
}
