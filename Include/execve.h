/*
** execve.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:45:20 2014 Maxime Limone
** Last update Fri May 23 18:18:23 2014 Maxime Limone
*/

#ifndef EXECVE_H_
# define EXECVE_H_
#include "tree.h"

void		check_point_slash(t_shell *sh, char **env);
int		exec_cmd(char *path, char **cmd, char **env, t_shell *sh);
int		exec_slah_bin(char **cmd, t_shell *sh);

#endif /* EXECVE_H_ */
