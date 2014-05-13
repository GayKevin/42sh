/*
** gere_pipes.c for gere_pipes in /home/limone_m/rendu/PSU_2013_minishell2
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu Mar  6 20:05:13 2014 Maxime Limone
** Last update Tue May  6 14:00:46 2014 Kevin Gay
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
#include "str_to_wordtab.h"
#include "my_put_tool.h"
#include "my_strcat.h"

int	check_pipes(t_shell *sh)
{
  t_pip	p;
  int	i;

  p.pi = -1;
  p.pi2 = -1;
  i = -1;
  while (sh->buffer[++i] != '\0')
    {
      if (sh->buffer[i] == '|')
	{
	  if (gere_pipes(sh, &p) == -1)
	    return (-1);
	  return (0);
	}
      if (sh->buffer[i] == ';')
      	if (p_point(sh, &p, i) == -1)
      	  return (-1);
    }
  return (0);
}

int	recup_pipes_cmd(t_shell *sh, t_pip *p)
{
  if ((p->cmd1 = malloc(sizeof(char) * strlen(sh->buffer))) == NULL)
    return (-1);
  memset(p->cmd1, 0, strlen(sh->buffer));
  if ((p->cmd2 = malloc(sizeof(char) * strlen(sh->buffer))) == NULL)
    return (-1);
  memset(p->cmd2, 0, strlen(sh->buffer));
  while (sh->buffer[++p->pi] != '|')
    p->cmd1[p->pi] = sh->buffer[p->pi];
  while (sh->buffer[++p->pi] != '\0')
    p->cmd2[++p->pi2] = sh->buffer[p->pi];
  p->tb_cmd1 = my_str_to_wordtab(p->cmd1);
  p->tb_cmd2 = my_str_to_wordtab(p->cmd2);
  return (0);
}

int	gere_pipes(t_shell *sh, t_pip *p)
{
  if (recup_pipes_cmd(sh, p) == -1)
    return (-1);
  if (pipe(p->pipefd) == -1)
    return (-1);
  if ((p->pid = fork()) == -1)
    return (-1);
  if (p->pid == 0)
    {
      if ((son_pipe(sh, p)) == -1)
	exit (-1);
	}
  else if (p->pid > 0)
    if ((master_pipe(sh, p)) == -1)
      exit (-1);
  return (0);
}

int	exec_cmd_pipe(t_shell *sh, t_pip *p, char *cmd)
{
  int	l;
  int	a;
  char	*pthcmd;

  l = -1;
  my_putstr(cmd);
  while (sh->path[++l] != '\0')
    {
      pthcmd = strcat(sh->path[l], cmd);
      a = access(pthcmd, X_OK);
      if (a == 0)
	{
	  execve(pthcmd, sh->cmd, sh->env);
	  return (0);
	}
    }
  my_putstr("\e[1;31Error : Command not found\e[0m\n");
  return (0);
}

char	*epur_str(char *str)
{
  int	i;
  int	id;
  char*	dest;

  i = 0;
  id = 0;
  if ((dest = malloc(sizeof(char) * strlen(str))) == NULL)
    return (NULL);
  memset(dest, 0, strlen(str));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    if ((str[i] == ' ' || str[i] == '\t') &&
        ((str[i + 1] == '\0') || (str[i + 1] == ' ' || str[i + 1] == '\t')))
      i++;
    else if ((str[i] == ' ' || str[i] == '\t') &&
             (str[i + 1] != ' ' && str[i + 1] != '\t'))
      {
	dest[id++] = ' ';
        i++;
      }
    else
      dest[id++] = str[i++];
  return (dest);
}
int	exec_cmd_pipe_fork(t_shell *sh, t_pip *p, char *cmd)
{
  int	l;
  int	a;
  char	*pthcmd;

  l = -1;
  cmd = epur_str(cmd);
  while (sh->path[++l] != '\0')
    {
      pthcmd = strcat(sh->path[l], cmd);
      a = access(pthcmd, X_OK);
     if (a == 0)
	{
	  p->pid = fork();
	  if (p->pid == 0)
	    execve(pthcmd, sh->cmd, sh->env);
	  else
	    if (wait(NULL) == -1)
	      return (-1);
	  return (0);
	}
    }
  my_putstr("\e[1;31Error : Command not found\e[0m\n");
  return (0);
}
