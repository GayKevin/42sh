/*
** shell.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 14:49:37 2014 Maxime Limone
** Last update Thu May  8 12:41:36 2014 Maxime Limone
*/

#ifndef SHELL_H_
# define SHELL_H_

int	check_op(char *buff, t_shell *sh);
int	shell(t_shell *sh);
int	read_buffer(t_shell *sh);

#endif /* SHELL_H_ */
