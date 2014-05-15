/*
** main.c for test in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu May 15 09:58:10 2014 Maxime Limone
** Last update Thu May 15 11:33:11 2014 Maxime Limone
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int		main(int argc, char **argv)
{
  kill(getpid(), atoi(argv[1]));
}
