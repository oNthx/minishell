#include "../../../inc/minishell.h"

t_env	*envpnew(char *str)
{
	t_env	*first;
	char	*tmp;

	tmp = ft_strchr(str, '=');
	first = malloc(sizeof(t_env));
	if (!first)
		return (0);
	first->key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(tmp));
	if (!(tmp + 1))
		first->value = ft_strdup("");
	else
		first->value = ft_substr(tmp + 1, 0, ft_strlen(tmp) - 1);
	first->fullstr = ft_strdup(str);
	first->next = 0;
	return (first);
}
