#ifndef SETENV_H_
# define SETENV_H

int	compare_env(t_shell *sh, int i, int p);
int	edit_env(t_shell *sh, int l, int i, int p);
int	add_env(t_shell *sh, int i, int p);
int	set_env(t_shell *sh, int i);

#endif /* SETENV */
