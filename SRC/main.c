/*
** main.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 16:15:36 2014 Maxime Limone
** Last update Thu May 15 13:08:30 2014 Kevin Gay
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "env.h"
#include "my_free.h"
#include "shell.h"
#include "my_strcat.h"
#include "my_putstr.h"

void	get_sigint(int sig)
{
  my_putstr("\n$> ");
}

int	main(int ac, char **av, char **env)
{
  t_shell sh;

  sh.re = 0;
  sh.cmd = NULL;
  signal(SIGINT, get_sigint);
  get_env(&sh, env);
  if (shell(&sh) == -1)
    {
      my_free(sh.path);
      my_free(sh.env);
      if (sh.c_ch != 0)
	free(sh.op_char);
      return (sh.re);
    }
  my_free(sh.path);
  my_free(sh.env);
  my_free(sh.cmd);
  return (0);
}
