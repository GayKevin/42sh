/*
** operator.h for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Tue May 13 21:32:23 2014 Maxime Limone
** Last update Tue May 13 22:59:35 2014 Kevin Gay
*/

#ifndef OPERATOR_H_
# define OPERATOR_H_

int	master_pipe(int pipefd[2], t_node *tree, t_shell *sh);
int	pipe_simple(t_node *tree, t_shell *sh);
int	db_pipe(t_node *tree, t_shell *sh);
int	left_chevron(t_node *tree, t_shell *sh);
int     right_chevron(t_node *tree, t_shell *sh);
int	and_and(t_node *tree, t_shell *sh);
int	and_simple(t_node *tree, t_shell *sh);
int	db_left(t_node *tree, t_shell *sh);
int	db_right(t_node *tree, t_shell *sh);
int	dotcom(t_node *tree, t_shell *sh);

#endif /* OPERATOR_H_ */