/*
** shell.h for 42sh in /home/limone_m/rendu/42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Fri May 23 18:20:02 2014 Maxime Limone
** Last update Fri May 23 18:20:03 2014 Maxime Limone
*/

#ifndef SHELL_H_
# define SHELL_H_
# include "tree.h"

int		check_cmd(t_shell *sh, t_node *tree);
int		check_op(char *buff, t_shell *sh);
int		shell(t_shell *sh);
int		read_buffer(t_shell *sh);

#endif /* SHELL_H_ */
