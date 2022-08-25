/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_related_builtins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:37:46 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/25 00:40:00 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_related_builtins(t_process *process, int pipes[2])
{
	close(pipes[0]);
	close(pipes[1]);
	if (!ft_strcmp(process->name, "cd"))
		cd(process);
	else if (!ft_strcmp(process->name, "exit"))
		ft_exit(process);
	else if (!ft_strcmp(process->name, "unset"))
		unset(process);
	else
		export(process);
	return (0);
}
