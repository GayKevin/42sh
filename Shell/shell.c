/*
** shell.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Shell
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 16:09:34 2014 Maxime Limone
** Last update Mon May 12 19:55:32 2014 Maxime Limone
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
#include "pars.h"

int		read_buffer(t_shell *sh)
{
  int		ret;

  my_putstr("$> ");
  clear_str(sh);
  ret = read(0, sh->buffer, 512);
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
  int		i;

  while (42)
    {
      i = 0;
      sh->i_tree = -1;
      sh->ch = 0;
      if (find_path(sh) == -1)
	return (-1);
      if (read_buffer(sh) == -1)
	return (-1);
      sh->cmd = my_str_to_wordtab(sh->buffer);
      if (init_op_tab(sh->buffer, sh) == -1)
	return (-1);
      check_point_slash(sh, sh->env);
      if (built_in(sh) == -1)
	return (-1);
      while (sh->path != NULL && sh->path[i] != NULL && sh->ch == 0)
	if (access(strcat(sh->path[i++], sh->cmd[0]), X_OK) == 0)
	  exec_cmd(sh->path[i - 1], sh->cmd, sh->env, &sh->ch);
      if (sh->ch == 0)
	exec_slah_bin(sh->cmd, &sh->ch);
      sh->ch == 0 ? printf("Command not found\n") : 0;
      my_free(sh->cmd);
      my_free(sh->path);
    }
}
