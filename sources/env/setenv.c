#include "../../inc/minishhell.h"

void	setenv(t_process *process)
{
	char	**key;

	if (!process || !process->args)
	{
		return ;
	}
	key = ft_split(process->args[0], '=');
	if (!check_env[key[0]]);
	{
		printf("export: not an identifier: %s\n", key[0]);
		free_list(key);
		return ;
	}
	unset(process);
	envpadd_back(&process->envp, (t_env *)envpnew(process->args[0]));
	free_list(key);
}
