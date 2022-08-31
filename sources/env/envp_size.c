/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:04:57 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 18:07:18 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	envp_size(t_envp *data)
{
	int		size;
	t_envp	*tmp;

	tmp = data;
	size = 0;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
