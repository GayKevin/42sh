/*
** parsing_tree.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 12 13:55:08 2014 Maxime Limone
<<<<<<< HEAD
** Last update Thu May 15 14:45:09 2014 Kevin Gay
=======
** Last update Thu May 15 14:35:43 2014 Maxime Limone
>>>>>>> 4334916c12130c541c652ec3c2ccfc46e294221a
*/

#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tree.h"
#include "shell.h"
#include "operator.h"

int		clearTree(t_node **tree)
{
  t_node	*tmp;

  tmp = *tree;
  if(!tree)
    return (0);
  if(tmp->left)
    clearTree(&tmp->left);
  if(tmp->right)
    clearTree(&tmp->right);
  free(tmp);
  *tree = NULL;
  return (0);
}

int		stock_tree(char *buff, t_shell *sh)
{
  int		j;
  int		k;

  if (((sh->left = malloc(sizeof(char) * strlen(buff))) == NULL)
      || ((sh->right = malloc(sizeof(char) * strlen(buff))) == NULL))
    return (-1);
  memset(sh->left, 0, strlen(buff));
  memset(sh->right, 0, strlen(buff));
  j = -1;
  k = -1;
  while (++j != sh->op_fnd_i[sh->op_i])
    sh->left[j] = buff[j];
  if (sh->db_op != 0)
    j++;
  while (buff[++j] != '\0')
    sh->right[++k] = buff[j];
  sh->check_l = 1;
  return (0);
}

void	tab_function_read(int (*tab_func[9])(t_node *tree, t_shell *sh))
{
  tab_func[0] = dotcom;
  tab_func[1] = and_simple;
  tab_func[2] = and_and;
  tab_func[3] = db_pipe;
  tab_func[4] = left_chevron;
  tab_func[5] = right_chevron;
  tab_func[6] = db_left;
  tab_func[7] = db_right;
  tab_func[8] = pipe_simple;
}

char		*tab_(char *tab)
{
  tab[0] = ';';
  tab[1] = '&';
  tab[2] = '+';
  tab[3] = '-';
  tab[4] = '<';
  tab[5] = '>';
  tab[6] = 'A';
  tab[7] = 'C';
  tab[8] = '|';
  return (tab);
}

int		gere_operator(t_node *tree, t_shell *sh)
{
  int		(*tab_func[9])(t_node *tree, t_shell *sh);
  char		*tab_tab;
  int		o;

  o = -1;
  if ((tab_tab = malloc(sizeof(char) * 9)) == NULL)
    return (-1);
  tab_tab = tab_(tab_tab);
  tab_function_read(tab_func);
  if (tree->chck_tree == 2)
    {
      while (tab_tab[++o] != tree->op);
      if ((tab_func[o](tree, sh)) == 1)
	return (1);
    }
  else
    if ((check_cmd(sh, tree)) == -1)
      {
	free(tab_tab);
  	return (-1);
      }
    {
      if ((check_cmd(sh, tree)) == -1)
	return (-1);
    }
  free(tab_tab);
  return (0);
}
