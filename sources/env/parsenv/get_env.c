/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:36:49 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 22:27:00 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_envp	*get_env(t_envp *envl, char *key)
{
	t_envp	*tmp;

	if (!envl)
		return (0);
	tmp  = envl;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			printf("aaaaa == %s\n", tmp->value);
			return (tmp);
		}
		tmp = tmp->next;
	}
	printf("aaaaa == %s\n", tmp->value);
	return (0);
}
