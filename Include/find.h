/*
** find.h for 42sh in /home/limone_m/rendu/42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Fri May 23 18:22:21 2014 Maxime Limone
** Last update Fri May 23 18:22:44 2014 Maxime Limone
*/

#ifndef FIND_H_
# define FIND_H

int		find_unsetenv(t_shell *sh, int i);
int		find_env(t_shell *sh, int i);
int		find_unset_env(t_shell *sh, int l, int i);
int		find_setenv(t_shell *sh, int i);

#endif /* FIND_H_ */
