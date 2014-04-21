#ifndef MAIN_H_
# define MAIN_H_

typedef struct	s_shell
{
  char		buffer[512];
  char		**path;
  char		**cmd;
  char		**env;
  char		*en;
  int		free_path;
  int		re;
  int		ch;
  int		d;
  int		j;
  int		o;
  int		p;
  int		m;
  int		a;
  int		l;
}		t_shell;

#endif /* MAIN */
