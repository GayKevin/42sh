/*
** main.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:47:14 2014 Maxime Limone
** Last update Wed May 14 02:25:45 2014 Kevin Gay
*/

#ifndef MAIN_H_
# define MAIN_H_
# include <unistd.h>

typedef struct		s_shell
{
  char			buffer[512];
  char			**cmd;
  char			**env;
  char			**path;
  char			*en;
  char			*op_fnd;
  char			*op_char;
  char			*left;
  char			*ps_1;
  char			*right;
  int			*op_fnd_i;
  char			db_op;
  int			op_i;
  int			free_path;
  int			i_tree;
  int			c_ch;
  int			r;
  int			re;
  int			ch;
  int			d;
  int			j;
  int			o;
  int			p;
  int			m;
  int			a;
  int			l;
}			t_shell;

typedef struct		s_pip
{
  char			**tb_cmd1;
  char			**tb_cmd2;
  char			*cmd1;
  char			*cmd2;
  char			*cmdp;
  int			pipefd[2];
  int			data;
  int			dup_0;
  int			dup_1;
  int			pi;
  int			pi2;
  pid_t			pid;
}			t_pip;

#endif /* MAIN */
