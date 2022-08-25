/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:07:00 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/25 02:12:12 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child(t_process  *process, int pipes[2])
{
	int	error;

	error = initfd(process, pipes);
	if (error)
		return (error);
	if (exec_builtin(process))
		exit(0);
	if (process->path && execve(process->path, process->args,
				deconstrict(process->envp)) == -1)
	{
		close(pipes[0]);
		close(pipes[1]);
		return (ER_EXEC);
	}
	exit(0);
}

void	parent(t_process *process)
{
	close(process->stdfd->_stdout);
	if (process->prev)
		close(process->prev->stdfd->_stdin);
}

void	set_stdfd(t_process *provess, int pipes[2])
{
	process->stdfd->_stdin = -1;
	process->stdfd->_stdout = -1;
	if (process->next)
	{
		process->stdfd->_stdin = pipes[0];
		process->stdfd->stdout = pipes[1];
	}
}
