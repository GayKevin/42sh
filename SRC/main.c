#include <signal.h>
#include <unistd.h>
#include "main.h"
#include "my_put_tool.h"
#include "env.h"
#include "my_free.h"
#include "shell.h"

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
  if (shell(&sh) == 1)
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
