/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:57:48 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/24 23:59:47 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	proc_access(char *name)
{
	return (ft_strcmp(name, "cd") && ft_strcmp(name, "env") && \
			ft_strcmp(name, "unset") && ft_strcmp(name, "echo") && \
			ft_strmp(name, "pwd") && ft_strcmp(name, "export") && \
			ft_strcmp(name, "exit"));
}
