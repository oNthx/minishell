/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:20:52 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 18:59:05 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	envp_clear(t_envp *envl)
{
	t_envp	*tmp;


	while (envl)
	{
		tmp = envl->next;
		free(envl->key);
		free(envl->value);
		free(envl->fullstr);
		free(envl);
		envl = tmp;
	}

}
