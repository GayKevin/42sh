/*
** pars.h for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu May  8 15:18:21 2014 Maxime Limone
** Last update Tue May 13 21:42:37 2014 Maxime Limone
*/

#ifndef PARS_H_
# define PARS_H_
# include "tree.h"

char		prio_op(char *buff, t_shell *sh);
int		change_double_char(char op, int i, int t, t_shell *sh);
int		check_op(char *buff, t_shell *sh, t_node *tree);
int		check_op_st(char *buff, int i, t_shell *sh);
int		gere_operator(t_node *tree, t_shell *sh);
int		init_op_tab(char *buff, t_shell *sh);
int		stock_tree(char *buff, t_shell *sh);

#endif /* PARS_H_ */
