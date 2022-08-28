/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_add_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:52:30 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 18:54:12 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	envp_add_front(t_envp **lst, t_envp *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	envp_add_back(&new, *lst);
}
