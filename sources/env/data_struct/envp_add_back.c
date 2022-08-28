/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:47:11 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 18:53:44 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	envp_add_back(t_envp **lst, t_envp *new)
{
	t_envp	*item;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	item = *lst;
	while (item->next)
		item = item->next;
	item->next = new;
}
