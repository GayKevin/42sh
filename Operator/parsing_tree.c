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
  if ((tab = malloc(sizeof(char) * 9)) == NULL)
    return (NULL);
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

  tab_tab = NULL;
  tab_tab = tab_(tab_tab);
  tab_function_read(tab_func);
  while (tab_tab[++o] != tree->op);
  if ((tab_func[o](tree, sh)) == 1)
    return (1);
}
