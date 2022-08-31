/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:11:19 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 20:14:49 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envp_delone(t_envp *data)
{
	if (!data)
		return ;
	free(data->key);
	free(data->value);
	free(data->fullstr);
	free(data);
}
