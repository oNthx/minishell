#include "../../../inc/minishell.h"

void	envpadd_back(t_env **lst, t_env *new)
{
	t_env	*item;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	item = *lst;
	while (item->next != 0)
		item = item->next;
	item->next = new;
}
