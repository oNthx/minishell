/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:03:58 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 20:29:47 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_envp	*envp_new(char *str)
{
	int		idx;
	t_envp	*new;

	idx = 0;
	new = malloc(sizeof(t_envp));
	if (!new)
		return (0);
	new->fullstr = ft_strdup(str);
	new->value = (ft_strchr(new->fullstr, '=') + 1);
	while (new->fullstr[idx] != '=')
		idx++;
	new->key = malloc(sizeof(char) * (idx + 1));
	idx = 0;
	while (new->fullstr[idx] != '=')
	{
		new->key[idx] = new->fullstr[idx];
		idx++;
	}
	return (new);
}
