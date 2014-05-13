/*
** gere_pipes2.c for gere_pipes2 in /home/limone_m/rendu/PSU_2013_minishell2
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Fri Mar  7 13:01:53 2014 Maxime Limone
** Last update Tue May  6 15:05:24 2014 Kevin Gay
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int	master_pipe(t_shell *sh, t_pip *p)
{
  if (wait(NULL) == -1)
    return (-1);
  if ((p->data = dup(0)) == -1)
    return (-1);
  close(p->pipefd[1]);
  if (dup2(p->pipefd[0], 0) == -1)
    return (-1);
  if (exec_cmd_pipe_fork(sh, p, p->cmd2, p->tb_cmd2) == -1)
    return (-1);
  if (dup2(p->data, 0) == -1)
    return (-1);
  return (0);
}

int	son_pipe(t_shell *sh, t_pip *p)
{
  close(p->pipefd[0]);
  if ((p->data = dup(1)) == -1)
    return (-1);
  if (dup2(p->pipefd[1], 1) == -1)
    {
      my_putstr("mlkmlkml");
      return (-1);
    }
  my_putstr("lol\n");
  if (exec_cmd_pipe(sh, p, p->cmd1, p->tb_cmd1) == -1)
    return (-1);
  my_putstr("lol\n");
  if (dup2(p->data, 1) == -1)
    return (-1);
  return (0);
}

int	p_point(t_shell *sh, t_pip *p, int i)
{
  int	ir;
  int	id;

  ir = i;
  id = 0;
  if ((p->cmdp = malloc(sizeof(char) * strlen(sh->buffer))) == NULL)
    return (-1);
  memset(p->cmdp, 0, strlen(sh->buffer));
  while (sh->buffer[ir - 1] != '\0' && sh->buffer[ir - 1] != ';')
    ir--;
  while (ir != i)
    p->cmdp[id++] = sh->buffer[ir++];
   check_access_p_p(sh, p);
  return (0);
}

int     check_access_p_p(t_shell *sh, t_pip *p)
{
  char	**av;

  av = my_str_to_wordtab(sh->buffer);
  //p->cmdp = epur_str(sh);
  my_putstr(av);
  /* if ((b = buin(s, av)) == 1) */
  /*   return (0); */
  /* else if (b == -1) */
  /*   return (-1); */
  if (built_in(sh) == 1)
    return (1);
  check_access2(sh, sh->cmd, av);
}

int	check_access2(t_shell *sh, char *cmd, char **av)
{
  int	a;
  int	l;
  pid_t	pid;
  int	status;
  char	*pthcmd;

  l = -1;
  while (sh->path[++l] != '\0')
    {
      pthcmd = strcat(sh->path[l], av[0]);
      a = access(pthcmd, X_OK);
      if (a == 0 || (strncmp(cmd, "./", 2) == 0))
        {
	  pid = fork();
          if (pid == 0)
	    my_exec(cmd, av, sh, pthcmd);
          else
            wait(&status);
          return (0);
        }
    }
  if (sh->path[l] == '\0')
    my_putstr("\e[1;31mError: Command not found\e[0m\n");
}

int	my_exec(char *cmd, char **av, t_shell *sh, char *pthcmd)
{
  if (strncmp(cmd, "./", 2) == 0)
    execve(av[0], av, sh->env);
  else
    execve(pthcmd, av, sh->env);
}
