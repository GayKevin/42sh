/*
** struct.h for struct.h in /home/gay_k/rendu/MUL_2013_wolf3d
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Sat Dec 14 13:01:27 2013 Kevin Gay
** Last update Thu Mar 13 17:16:41 2014 Kevin Gay
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_shell
{
  char		buffer[512];
  char		**path;
  char		**cmd;
  char		**env;
  int		ch;
  int		d;
  int		j;
  int		o;
  int		p;
  int		m;
  int		a;
}		t_shell;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr(int nbr);
int	printf_error(const char *format, ...);
void	clear_str(t_shell *sh);
int	shell(t_shell *sh, char **env);
int	read_buffer(t_shell *sh);
void	clear_str_env(t_shell *sh, int nb);
void	get_env(t_shell *sh, char **env);
char	*clean_path(char *str);
int	path(t_shell *sh, char *env);
int	find_path(t_shell *sh);
void	my_free(char **str);
char	**my_str_to_wordtab(char *str);
int	find_cd(t_shell *sh, int i);
int	find_unsetenv(t_shell *sh, int i);
int	find_env(t_shell *sh, int i);
int	my_strcmp(char *str1, char *str2);
int	my_strcmp_(char *str1, char *str2);
int	find_unset_env(t_shell *sh ,int l, int i);
int	unset_env(t_shell *sh, int i);
int     my_strlen(char *str);
void    my_show_tab(char **tab);
int	built_in(t_shell *sh);
void	check_point_slash(t_shell *sh, char **env);
char	*my_strcat(char *dest, char *src);
int	exec_cmd(char *path, char **cmd, char **env, int *check);
char    *my_strcpy(char *dest, char *src);
int	find_setenv(t_shell *sh, int i);
int	compare_env(t_shell *sh, int i, int p);
int	edit_env(t_shell *sh, int l, int i, int p);
int	add_env(t_shell *sh, int i, int p);
int	set_env(t_shell *sh, int i);
#endif
