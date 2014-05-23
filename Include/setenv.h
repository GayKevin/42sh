/*
** setenv.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 14:48:36 2014 Maxime Limone
** Last update Fri May 23 18:17:48 2014 Maxime Limone
*/

#ifndef SETENV_H_
# define SETENV_H

int		compare_env(t_shell *sh, int i, int p);
int		edit_env(t_shell *sh, int l, int i, int p);
int		add_env(t_shell *sh, int i, int p);
int		set_env(t_shell *sh, int i);

#endif /* SETENV_H_ */
