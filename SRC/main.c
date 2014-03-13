/*
** main.c for main in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Mon Mar 10 11:38:58 2014 Kevin Gay
** Last update Thu Mar 13 13:14:22 2014 Kevin Gay
*/

#include <signal.h>
#include <unistd.h>
#include "struct.h"

void	get_sigint(int sig)
{
  my_putstr("\n$>");
}

int	main(int ac, char **av, char **env)
{
  t_shell sh;

  sh.cmd = NULL;
  signal(SIGINT, get_sigint);
  get_env(&sh, env);
  if (shell(&sh, env) == 1)
    {
      my_free(sh.path);
      my_free(sh.env);
      return (0);
    }
  my_free(sh.path);
  my_free(sh.env);
  my_free(sh.cmd);
  return (0);
}
