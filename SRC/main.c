#include <signal.h>
#include <unistd.h>
#include "struct.h"

void	get_sigint(int sig)
{
  my_putstr("\n$>");
}

int	main(int ac, char **av, char **env)
{
  t_shell sh;

  sh.re = 0;
  sh.cmd = NULL;
  signal(SIGINT, get_sigint);
  get_env(&sh, env);
  if (shell(&sh, env) == 1)
    {
      my_free(sh.path);
      my_free(sh.env);
      return (sh.re);
    }
  my_free(sh.path);
  my_free(sh.env);
  my_free(sh.cmd);
  return (0);
}
