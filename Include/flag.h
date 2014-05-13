/*
** flag.h for 42sh in /home/limone_m/rendu/PSU_2013_42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 11:46:50 2014 Maxime Limone
** Last update Mon May  5 11:46:52 2014 Maxime Limone
*/

#ifndef		FLAG_H_
# define	FLAG_H_
#include	<stdarg.h>

typedef		void (*flag)(va_list list);

void		numbers(va_list list);
void		sentence(va_list list);
void		character(va_list list);
void		modulo();
void		printf_b(unsigned int nbr);
void		my_puterror(char c);
void		my_putstr_e(char *str);
void		my_put_nbr_e(int nb);

#endif /* FLAG_H_ */
