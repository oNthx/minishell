#include "../../inc/minishell.h"

static char	*envl_join(char *key, char *value)
{
	char	*tmp;
	char	*res;

	if (!key)
		return (0);
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (0);
	if (!value)
		return (tmp);
	res = ft_strjoin(tmp, value);
	free(tmp);
	if (!res)
		return (0);
	return (res);
}
