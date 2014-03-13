/*
** shell.c for shell in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Mon Mar 10 15:32:07 2014 Kevin Gay
** Last update Thu Mar 13 16:58:45 2014 Kevin Gay
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

int	read_buffer(t_shell *sh)
{
  int	ret;

  my_putstr("$>");
  clear_str(sh);
  if ((ret = read(0, sh->buffer, 512)) == -1)
    {
      my_putstr("\n");
      read_buffer(sh);
    }
  if (ret == 0)
    return (1);
  sh->buffer[ret - 1] = '\0';
  return (0);
}


int	shell(t_shell *sh, char **env)
{
  int	i;

  while (42)
    {
      i = 0;
      sh->ch = 0;
      if (find_path(sh) == 1)
	return (1);
      if (read_buffer(sh) == 1)
	return (1);
      sh->cmd = my_str_to_wordtab(sh->buffer);
      check_point_slash(sh, env);
      if (built_in(sh) == 1)
	return (1);
      while (sh->path != NULL && sh->path[i] != NULL && sh->ch == 0)
	if (access(my_strcat(sh->path[i++], sh->cmd[0]), X_OK) == 0)
	  exec_cmd(sh->path[i - 1], sh->cmd, env, &sh->ch);
      sh->path[i] == NULL ? my_putstr("Command not found\n") : 0;
      my_free(sh->cmd);
      my_free(sh->path);
    }
}
