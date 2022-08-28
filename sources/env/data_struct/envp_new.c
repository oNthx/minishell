/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:14:42 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 18:59:43 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_envp	*envp_new(char *str)
{
	char	*tmp;
	t_envp	*first;
	
	tmp = ft_strchr(str, '=');
	first = malloc(sizeof(t_envp));
	if (!first)
		return (0);
	first->key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(tmp) - 1);
	if (!(tmp + 1))
		first->value = ft_strdup("");
	else
		first->value = ft_substr(tmp + 1, 0, ft_strlen(tmp) - 1);
	first->fullstr = ft_strdup(str);
	first->next = 0;
	return (first);
}
