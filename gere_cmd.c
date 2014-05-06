/*
** gere_cmd.c for gere_cmd in /home/limone_m/rendu/PSU_2013_minishell2
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu Mar  6 18:36:44 2014 Maxime Limone
** Last update Tue May  6 11:44:36 2014 Kevin Gay
*/

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "my_put_tool.h"

int	check_access_pipe(t_shell *sh)
{
  int	p;

  if ((p = check_pipes(sh)) == 1)
    {
      sh->ch = 1;
      return (0);
    }
  if (p == -1)
    {
      my_putstr("\e[1;31mError : error pipe\e[0m\n");
      sh->ch = 1;
      return (-1);
    }
  return (0);
}
