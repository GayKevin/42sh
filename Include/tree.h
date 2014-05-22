/*
** tree.h for 42sh in /home/limone_m/rendu/42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May  7 13:15:35 2014 Maxime Limone
** Last update Thu May 22 15:25:55 2014 Kevin Gay
*/

#ifndef TREE_H_
# define TREE_H_

typedef struct		s_node
{
  char			chck_tree;
  char			op;
  char			*str;
  struct s_node		*left;
  struct s_node		*right;
}			t_node;

int			add_node(t_node *node, char *str_lf, char *str_rg);
int			clearTree(t_node **tree);
t_node			*create_r(char op_r);
void			display_tree(t_node *root);

#endif /* TREE_H_ */
