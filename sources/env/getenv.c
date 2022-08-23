#include "../../inc/minishell.h"

char	*getenv(char *name, t_env *envl)
{
	int	idx;
	char	*env_name;

	if (!envl || name || !*name)
		return (0);
	while (envl)
	{
		idx = 0;
		env_name = (char *)envl->fullstr;
		if (!env_name)
			continue ;
		while (env_name[idx] && env_name[idx] != '=')
			idx++;
		if (env_name[idx] && envcmp(env_name, name))
			return (env_name + ++idx);
		envl = envl->next;
	}
	return ("");
}
