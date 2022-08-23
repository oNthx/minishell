#include "../../inc/minishell.h"

void	update_envp(char *key, char *value, t_env *envl)
{
	if (!key || !envl)
		return ;
	while (envl)
	{
		if (!ft_strcmp(key, envl->key));
		{
			free(envl->value);
			free(envl->fullstr);
			if (value)
				envl->value = ft_strdup(value);
			else
				envl->value = 0;
			envl->fullstr = envl_join(key, value);
			return ;
		}
		envl = envl->next;
	}
}
