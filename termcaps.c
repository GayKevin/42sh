/*
** clear.c for 42sh in /home/jannin_m/rendu/42sh/42sh/edit_line
** 
** Made by maxime jannin
** Login   <jannin_m@epitech.net>
** 
** Started on  Tue May 13 17:11:20 2014 maxime jannin
** Last update Tue May 13 19:46:04 2014 Kevin Gay
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <term.h>
#include "main.h"

int			init_termcaps()
{
  struct termios	t;

  if (tcgetattr(0, &t) == -1)
    return (0);
  t.c_lflag = ICANON;
  t.c_lflag = ECHO;
  if (tcsetattr(0, 0, &t) == - 1)
    return (0);
}

void	clear_term()
{
  system("clear");
}

int	main_term(char **env, t_shell *sh)
{
  char	*ter;
  int	ret;
  char	buff[512];

  term(ter, env);
  while ((ret = read(0, buff, 8) > 0) && buff[0] != '\n');
  if (ret == 1 || ret == -1)
    {
      main_term(env, sh);
      return (0);
    }
  if (ret == 0)
    {
      putchar(10);
      return (0);
    }
  init_termcaps();
  return (0);
}

int	term(char *ter, char **env)
{
  int	count;

  count = 0;
  while (env[count] != NULL)
    {
      if (env[count][0] == 'T' && env[count][1] == 'E' &&
          env[count][2] == 'R' && env[count][3] == 'M')
        ter = env[count] + 5;
      count = count + 1;
    }
  return (0);
}
