#include "../../../inc/minishell.h"

void	envpclear(t_env *envl)
{
	t_envp	*tmp;

	while (envl)
	{
		tmp = envl->next;
		free(envl->key);
		free(envl->value);
		free(envl->fullstr);
		free(envl);
		envl = tmp;
	}
}
