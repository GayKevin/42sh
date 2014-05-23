/*
** left_chevron.c for left_chevron in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:38:27 2014 Kevin Gay
** Last update Fri May 23 19:38:13 2014 Kevin Gay
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "main.h"
#include "errno.h"
#include "my_errno.h"
#include "operator.h"
#include "tree.h"
#include "pars.h"
#include "epur_str.h"

int		left_chevron(t_node *tree, t_shell *sh)
{
  int		dup_fd[2];
  pid_t		pid;

  if (check_err_chevron(tree, sh) == -1)
    return (-1);
  if ((dup_fd[0] = open(tree->right->str, O_RDONLY)) == -1)
    {
      if (find_errno(sh) == -1)
	printf("KO\n");
      return (-1);
    }
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((dup_fd[1] = dup(0)) == -1)
	return (-1);
      if ((dup2(dup_fd[0], 0)) == -1)
	return (-1);
      gere_operator(tree->left, sh);
      exit(1);
    }
  else
    {
      if (left_chevron_afterpart(dup_fd, tree, sh) == -1)
	return (-1);
    }
  return (0);
}

int		left_chevron_afterpart(int dup_fd[2], t_node *tree, t_shell *sh)
{
  if ((wait(NULL)) == -1)
    exit(0);
  if ((dup2(dup_fd[1], 0)) == -1)
    return (-1);
  return (0);
}

int		check_err_chevron(t_node *tree, t_shell *sh)
{
  int		t;

  t = -1;
  if (tree->right->str[0] == '\0')
    {
      fprintf(stderr, "Syntax error: about the symbol '%c'\n", tree->op);
      return (-1);
    }
  while ((tree->right->str[0] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0')
    {
      fprintf(stderr, "Syntax error: about the symbol '%c'\n", sh->op_char[t]);
      return (-1);
    }
  if (tree->left->str[0] == '\0')
    if (change_chevron(tree, sh) == -1)
      return (-1);
  return (0);
}

int		change_chevron(t_node *tree, t_shell *sh)
{
  char		*buff;
  int		i;
  int		b;

  i = -1;
  b = -1;
  if ((buff = malloc(sizeof(char) * (strlen(tree->right->str) + 1))) == NULL)
    return (-1);
  memset(buff, 0, strlen(tree->right->str));
  while (tree->right->str[++i] != ' ' && tree->right->str[i] != '\0');
  while (tree->right->str[++i] != '\0')
    {
      buff[++b] = tree->right->str[i];
      tree->right->str[i] = ' ';
    }
  buff[++b] = '\0';
  tree->right->str = epur_str(tree->right->str);
  strcpy(tree->left->str, buff);
  free(buff);
  return (0);
}
