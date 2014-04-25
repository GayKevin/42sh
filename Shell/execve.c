#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"
#include "my_put_tool.h"
#include <stdio.h>
#include <string.h>
#include "my_strcat.h"

int	exec_cmd(char *path, char **cmd, char **env, int *ch)
{
  pid_t	pid;
  int	status;

  *ch = 1;
  if ((pid = fork()) == -1)
    return (0);
  if (pid > 0)
    wait(&status);
  else if (pid == 0)
    if ((execve(path, cmd, env)) == -1)
      {
	//	  printf_error("Segmentation Fault\n");
	printf("execve11 : %d\n", status);
	exit (0);
      }
  return (0);
}

int	exec_slah_bin(char **cmd, int *ch)
{
  pid_t	pid;
  int	status;
  int	i;

  i = -1;
  while (cmd[++i] != NULL)
    if (cmd[i][0] == '/')
      {
	if ((pid = fork()) == -1)
	  return (0);
       	if (pid > 0)
	  waitpid(pid, &status, 0);
        else if (pid == 0)
	  if ((execve(cmd[i], cmd, NULL)) == -1)
	    {
	      printf("execve : %d\n", status);
	      return (0);
	    }
	*ch = 1;
      }
  return (0);
}

int	check_point_slash(t_shell *sh, char **env)
{
  int	i;
  int	l;
  char	*path;

  i = -1;
  while (sh->cmd[++i] != NULL)
    {
      l  = -1;
      while (sh->cmd[i][++l] != '\0')
	{
	  if (sh->cmd[i][l] == '.' && sh->cmd[i][l + 1] == '/')
	    {
	      path = malloc(sizeof(char) * 1024);
	      memset(path, 0, 1024);
	      path = getcwd(path, 1024);
	      my_strcat_slash(path, sh->cmd[i]);
	      exec_cmd(path, sh->cmd, env, &sh->ch);
	      free(path);
	      return (0);}
	}
    }
  return (0);
}
