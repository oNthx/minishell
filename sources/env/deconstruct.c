#include "../../inc/minishell.h"

char	**deconstruct(t_envp *envl)
{
	size_t	idx;
	size_t	size;
	char	**envp;

	idx = 0;
	size = ft_envpsize(envl);
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	while (idx < size)
	{
		envp[idx++] = ft_strdup((char *)envl->fullstr);
		envl = envl->next;
	}
	envp[idx] = 0;
	return (envp);
}
