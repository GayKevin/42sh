/*
** main.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:47:14 2014 Maxime Limone
** Last update Tue May  6 13:42:52 2014 Kevin Gay
*/

#ifndef MAIN_H_
# define MAIN_H_
#include <unistd.h>

typedef struct	s_shell
{
  char		buffer[512];
  char		**path;
  char		**cmd;
  char		**env;
  char		*en;
  int		free_path;
  int		re;
  int		ch;
  int		d;
  int		j;
  int		o;
  int		p;
  int		m;
  int		a;
  int		l;
}		t_shell;


typedef struct		s_pip
{
  char	**tb_cmd1;
  char	**tb_cmd2;
  char	*cmd1;
  char	*cmd2;
  char	*cmdp;
  int	pipefd[2];
  int	data;
  int	dup_0;
  int	dup_1;
  int	pi;
  int	pi2;
  pid_t	pid;
}			t_pip;


#endif /* MAIN */
