#include <stdlib.h>
#include "main.h"
#include "my_put_tool.h"

void    my_show_tab(char **tab)
{
  int    i;

  i = -1;
  while (tab[++i] != NULL)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
    }
}
