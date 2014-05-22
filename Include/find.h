/*
** find.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:45:50 2014 Maxime Limone
** Last update Mon May  5 11:45:51 2014 Maxime Limone
*/

#ifndef FIND_H_
# define FIND_H

int	find_unsetenv(t_shell *sh, int i);
int	find_env(t_shell *sh, int i);
int	find_unset_env(t_shell *sh, int l, int i);
int	find_setenv(t_shell *sh, int i);

#endif /* FIND */
