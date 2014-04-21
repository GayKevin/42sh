#ifndef EXECVE_H_
# define EXECVE_H_

void	check_point_slash(t_shell *sh, char **env);
int	exec_cmd(char *path, char **cmd, char **env, int *check);
int	exec_slah_bin(char **cmd, int *ch);

#endif /* EXECVE */
