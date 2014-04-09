 #include "struct.h"

void	clear_str(t_shell *sh)
{
  int	i;

  i = -1;
  while (++i != 512)
    sh->buffer[i] = '\0';
}
