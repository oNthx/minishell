/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:17:55 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/27 18:58:55 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envp_delone(t_envp *envp, void (*del)(void *))
{
	if (!envp)
		return ;
	del(envp->key);
	del(envp->value);
	del(envp->fullstr);
	free(envp);
}
