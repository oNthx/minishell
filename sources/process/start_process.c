/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:40:22 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/25 02:06:41 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	run(t_process *process);
static int	redirect(t_process *process);

int	start_process(t_process *process)
{
	int	ret;

	if (!process)
		return (ER_NOPROC);
	while (process)
	{
		ret = run(process);
		if (ret)
			return (ret);
		process = process->next;
	}
	return (0);
}

static int	run(t_process *process)
{
	int	pipes[2];

	pipes[0] = -1;
	pipes[1] = -1;
	if (access(process->path, F_OK) && proc_access(process->name))
	{
		if (!process->path)
			return (ft-error(process, ER_NOCOMM));
		return (ft_error(process, ER_NOFILE));
	}
	if (access(process->path, X_OK) && proc_access(process->name))
		return (ft_error(process, ER_ACCES));
	set_stdfd(process, pipes);
	if (!process->next && !process->prev && is_relatedbuiltin(process->name))
		return (run_related_builtins(process, pipes));
	process->pid = fork();
	if (!process->pid)
		child(process, pipes);
	else
		paret(process);
	return (0);
}

int	intifd(t_process *process, int pipes[2])
{
	int	res;

	(void)pipes;
	res = redirect(process);
	if (res)
		return (res);
	if (process->prev && \
			!process->redirect->read && !process->redirect->delimeter && \
			dup2(process->prev->stdfd->_stdin, 0) == -1)
		return (ERROR);
	if (process->next && \
			!process->redirect->write && !process->redirect->overwrite && \
			dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	return (res);
}

static int	redirect(t_process *process)
{
	if (process->redirect->delimeter)
		red_delimeter(process->redirect->delimeter, !!process->redirect->.read);
	if (process->redirect->read)
		red_read(process->redirect->read);
	if (process->readirect->write)
		red_write(process->redirect->write);
	if (process->redirect->overwrite)
		red_overwrite(process->redirect->overwrite);
	return (0);
}
