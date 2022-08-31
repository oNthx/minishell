/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:11:20 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 20:10:55 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envp_add_back(t_envp **data, t_envp *new)
{
	t_envp	*tmp;

	if (!data || !new)
		return ;
	if (!*data)
	{
		*data = new;
		return ;
	}
	tmp = *data;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
