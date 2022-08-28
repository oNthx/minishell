/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:17:29 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/28 15:14:06 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envl)
{
	t_envp		*data;
	t_process	*proc;

	printf("here i'm\n");
	argc = (int)argc;
	argv = (char **)argv;
	proc = malloc(sizeof(t_process));
	data = malloc(sizeof(t_envp));
	proc->envp = data;
	printf("here i'm\n");
	get_env(envl, data);
	printf("here i'm\n");
	printf("data->key %s\n", data->key);
	if (ft_strcmp(data->key, "PWD") == 0)
	{
		printf("here i'm\n");
		set_env(proc);
	}
}
