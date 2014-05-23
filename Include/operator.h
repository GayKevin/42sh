/*
** operator.h for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Tue May 13 21:32:23 2014 Maxime Limone
** Last update Fri May 23 17:41:46 2014 Maxime Limone
*/

#ifndef OPERATOR_H_
# define OPERATOR_H_
# include "tree.h"
# include "main.h"

char		*stock_name(char *str);
int		check_err_chevron(t_node *tree, t_shell *sh);
int		check_err_dotcom(t_node *tree, t_shell *sh);
int		check_err_op(t_node *tree, t_shell *sh);
int		check_err_pipe(t_node *tree, t_shell *sh);
int		change_chevron(t_node *tree, t_shell *sh);
int		master_pipe(int pipefd[2], t_node *tree, t_shell *sh);
int		pipe_simple(t_node *tree, t_shell *sh);
int		read_cmd_op(t_node *tree, t_shell *sh);
int		master_pipe(int pipefd[2], t_node *tree, t_shell *sh);
int		pipe_simple(t_node *tree, t_shell *sh);
int		db_pipe(t_node *tree, t_shell *sh);
int		left_chevron(t_node *tree, t_shell *sh);
int		left_chevron_afterpart(int dup_fd[2], t_node *tree, t_shell *sh);
int		right_chevron(t_node *tree, t_shell *sh);
int		and_and(t_node *tree, t_shell *sh);
int		and_simple(t_node *tree, t_shell *sh);
int		db_left(t_node *tree, t_shell *sh);
int		db_left_afterpart(char *buff_w, t_node *tree, t_shell *sh);
int		db_left_afterpart_master(int pipefd[2], t_node *tree, t_shell *sh);
int		db_right(t_node *tree, t_shell *sh);
int		dotcom(t_node *tree, t_shell *sh);

#endif /* OPERATOR_H_ */
