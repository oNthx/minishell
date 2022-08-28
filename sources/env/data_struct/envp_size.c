/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:33:33 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 12:36:57 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	envp_size(t_envp *envl)
{
	int		size;
	t_envp	*tmp;

	size = 0;
	if (!envl)
		return (0);
	tmp = envl;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
