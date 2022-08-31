/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:22:51 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 20:29:22 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(char *line)
{
	return (!ft_strcmp(line, "cd") || !ft_strcmp(line, "echo") || \
		!ft_strcmp(line, "pwd") || !ft_strcmp(line, "export") || \
		!ft_strcmp(line, "env") || !ft_strcmp(line, "exit") || \
		!ft_strcmp(line, "unset"));
}
