/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:15:12 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 20:18:48 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envp_clear(t_envp *data)
{
	t_envp	*tmp;

	while (data)
	{
		tmp = data->next;
		free(data->key);
		free(data->value);
		free(data->fullstr);
		free(data);
		data = tmp;
	}
}
