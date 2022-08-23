#include "../../inc/minishell.h"

t_env	*construct(char **envp)
{
	static int	init;
	t_env		*envl;
	int		idx;

	idx = 0;
	init = 0;
	if (!envp)
		return (0);
	while (envp[idx])
		envpadd_back(&envl, envpnew(envp[idx++]));
	if (!init++)
		envp_add_back(&envl, envpnew("?=0"));
	return (envl);
}
