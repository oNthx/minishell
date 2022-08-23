#include "../../../inc/minishell.h"

int	envpsize(t_env *lst)
{
	t_env	*tmp;
	int	count;

	count = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
