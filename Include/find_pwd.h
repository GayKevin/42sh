#ifndef FIND_PWD_H_
# define FIND_PWD_H

int	find_pwd_env(t_shell *sh);
void	find_point(t_shell *sh, int d);
void	find_slash(t_shell *sh, int d, int i, char *cmd);
int	find_slash_2(t_shell *sh, int d, int i, char *cmd);
int	find_first_slash(t_shell *sh, int d, char *cmd);

#endif /* FIND_PWD */
