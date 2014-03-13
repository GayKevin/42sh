/*
** flag.h for flag in /home/gay_k/printf
** 
** Made by Kévin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri Nov 15 20:31:39 2013 Kévin Gay
** Last update Wed Mar 12 23:40:39 2014 Kevin Gay
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


#endif
