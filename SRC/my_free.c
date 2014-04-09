#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void	my_free(char **str)
{
  int	i;

  i = -1;
  if (str)
    {
      while (str[++i] != NULL)
	free(str[i]);
      free(str);
    }
}
