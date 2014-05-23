/*
** my_errno.h for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 19 13:57:52 2014 Maxime Limone
** Last update Fri May 23 19:20:58 2014 Kevin Gay
*/

#ifndef MY_ERRNO_H_
# define MY_ERRNO_H_

int		find_errno(t_shell *sh);
typedef struct		s_ernol
{
  char			**erno;
}			t_erno;

#endif /* MY_ERRNO_H_ */
