/*
** tree.h for 42sh in /home/limone_m/rendu/42sh/Include
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May  7 13:15:35 2014 Maxime Limone
** Last update Tue May 13 22:38:16 2014 Maxime Limone
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
t_node			*create_r(char op_r);
void			display_tree(t_node *root);

#endif /* TREE_H_ */
