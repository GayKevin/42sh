/*
** shell.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 14:49:37 2014 Maxime Limone
** Last update Wed May 14 02:24:28 2014 Kevin Gay
*/

#ifndef SHELL_H_
# define SHELL_H_
# include "tree.h"

int	check_cmd(t_shell *sh, t_node *tree);
int	check_op(char *buff, t_shell *sh);
int	shell(t_shell *sh);
int	read_buffer(t_shell *sh);

#endif /* SHELL_H_ */
