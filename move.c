/*
** move.c for 42sh in /home/jannin_m/rendu/42sh/42sh/edit_line
** 
** Made by maxime jannin
** Login   <jannin_m@epitech.net>
** 
** Started on  Tue May 13 18:47:05 2014 maxime jannin
** Last update Tue May 13 19:20:44 2014 Kevin Gay
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <term.h>

int	termcap_touch(char *buff)
{
  /* if (buff[2] == 'B') */
  /*   //up_in_hystory(history); */
  /* else if (buff[2] == 'A') */
  /*   //down_in_history(history); */
  /* else if (buff[2] == 'C') */
  /*   //go_on_right(buff); */
  /* else if (buff[2] == 'D') */
  /*   //go_on_left(buff); */
}

int			my_move(char *buff, char *term)
{
  struct termios	t;

  if (tgetent(NULL, term) == -1)
    return (0);
  tcgetattr(0, &t);
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  tcsetattr(0, 0, &t);
  termcap_touch(buff);
  return (0);
}
