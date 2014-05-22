/*
** parsing.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu May  8 15:12:42 2014 Maxime Limone
** Last update Thu May 22 18:23:17 2014 Kevin Gay
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "pars.h"
#include "tree.h"
#include "epur_str.h"
#include "free_stuff.h"

int             parsing_main(char *buff, t_shell *sh)
{
  t_node	*tree;

  init_op_tab(sh);
  if ((tree = malloc(sizeof(t_node))) == NULL)
    return (-1);
  memset(tree, 0, sizeof(t_node));
  tree->left = NULL;
  tree->right = NULL;
  if (check_op(buff, sh, tree) == 1);
  /* display_tree(tree); */
  if ((gere_operator(tree, sh)) == -1)
    {
      free_stuff(sh, tree);
      return (-1);
    }
  free_stuff(sh, tree);
  return (0);
}

int		check_op(char *buff, t_shell *sh, t_node *tree)
{
  int		i;
  char		op_f;
  char		*buf;

  buf = malloc(sizeof(char) * (strlen(buff) + 5));
  memset(buf, 0, strlen(buff));
  strcpy(buf, buff);
  tree->str = malloc(sizeof(char) * (strlen(buf) + 5));
  memset(tree->str, 0, (strlen(buf) + 5));
  strcpy(tree->str, buf);
  tree->str = epur_str(tree->str);
  i = -1;
  sh->r = 0;
  ++sh->i_tree;
  sh->db_op = 0;
  while (buf[++i] != '\0')
    i = check_op_st(buf, i, sh);
  if (sh->r == 0)
    {
      free(buf);
      return (1);
    }
  sh->op_fnd[sh->r] = '\0';
  sh->op_fnd_i[sh->r] = '\0';
  op_f = prio_op(buf, sh);
  stock_tree(buf, sh);
  free(buf);
  if (op_f == 0)
    tree->chck_tree = 0;
  else
    tree->chck_tree = 2;
  tree->op = op_f;
  add_node(tree, epur_str(sh->left), epur_str(sh->right));
  check_op(tree->left->str, sh, tree->left);
  check_op(tree->right->str, sh, tree->right);
  return (0);
}

int		check_op_st(char *buff, int i, t_shell *sh)
{
  int		t;

  t = -1;
  while ((buff[i] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0')
    {
      if ((sh->op_fnd = realloc(sh->op_fnd, sizeof(char) * ++sh->r)) == NULL)
	return (-1);
      if ((sh->op_fnd_i = realloc(sh->op_fnd_i, sizeof(int) * sh->r)) == NULL)
	return (-1);
      if (buff[i + 1] == sh->op_char[t] && t < 4)
	return(change_double_char(sh->op_char[t], i, t, sh));
      else
	{
	  sh->op_fnd[sh->r - 1] = sh->op_char[t];
          sh->op_fnd_i[sh->r - 1] = i;
	}
    }
  return (i);
}

int		change_double_char(char op, int i, int t, t_shell *sh)
{
  if (op == '|')
    sh->op_fnd[sh->r - 1] = '-';
  else
    sh->op_fnd[sh->r - 1] = sh->op_char[t] + 5;
  sh->op_fnd_i[sh->r - 1] = i++;
  return (i++);
}

char		prio_op(char *buff, t_shell *sh)
{
  int		i;
  char		op_f;
  char		brk;

  i = -1;
  sh->op_i = -1;
  brk = 0;
  op_f = '~';
  while (brk == 0 && (sh->op_fnd[++i] != '\0'))
    if (sh->op_fnd[i] == ';')
      {
	op_f = sh->op_fnd[i];
	sh->op_i = i;
	brk = 1;
      }
    else
      if (sh->op_fnd[i] < op_f && sh->op_fnd[i] != '\0')
	{
	  op_f = sh->op_fnd[i];
	  sh->op_i = i;
	}
  if (op_f == '-' || op_f == '+' || op_f == 'A' || op_f == 'C')
    sh->db_op = 2;
  return (op_f);
}
