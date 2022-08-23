#include "../../../inc/minishell.h"

void	envpdelone(t_env *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->key);
	del(lst->value);
	del(lst->fullstr);
	free(lst);
}
