#ifndef FIND_H_
# define FIND_H

int	find_unsetenv(t_shell *sh, int i);
int	find_env(t_shell *sh, int i);
int	find_unset_env(t_shell *sh, int l, int i);
int	find_setenv(t_shell *sh, int i);

#endif /* FIND */
