#include <string.h>
#include <stdlib.h>
#include "struct.h"

void	my_malloc_pwd(t_shell *sh, int d, char *cmd)
{
  sh->l = my_strlen(sh->env[d]);
  sh->en = malloc(sizeof(char) * (strlen(sh->env[d]) + strlen(cmd) + 2));
  memset(sh->en, 0, (strlen(sh->env[d]) + strlen(cmd) + 2));
  my_strcpy(sh->en, sh->env[d]);
  free(sh->env[d]);
  sh->env[d] = malloc(sizeof(char) * (strlen(sh->en)) + 10);
  memset(sh->env[d], 0, strlen(sh->en) + 10);
}
