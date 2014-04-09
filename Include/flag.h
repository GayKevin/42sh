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
