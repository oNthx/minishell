/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:26:47 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/28 11:22:59 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_envp	*get_env(char **envl, t_envp *data)
{
	int		idx;
	t_envp	*tmp;

	idx = 0;
	data = envp_new(envl[idx]);
	tmp = data;
	while (envl[++idx])
	{
		tmp->next = envp_new(envl[idx]);
		tmp = tmp->next;
	}
	return (data);
}
