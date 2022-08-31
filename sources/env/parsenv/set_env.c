/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:33:40 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 22:42:10 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_process	*set_path(t_envp *envl)
{
	int			idx;
	char		**part;
	t_process	*data;

	idx = 0;
	printf("BBBBBBBBB\n");
	data = malloc(sizeof(t_process));
	printf("BBBBBBBBB\n");
	if (!data)
		return (0);
	printf("BBBBBBBB\n");
	envl = get_env(envl, "PATH");
	printf("AAAAAA== %s ==AAAAA\n", envl->key);
	part = ft_split(envl->value, ':');
	while (part && part[idx])
	{
		data->path[idx] = part[idx];
		idx++;
	}
	free_split(part);
	return (data);
}

int	main(int argc, char **argv, char **envl)
{
	t_process	*data;
	t_envp		*envp;

	(void)argc;
	argv = (char **)argv;
	printf("AAAAAAAAAAAAAAAAA\n");
	envp = 0;
	for ( int i = 0; envl[i]; i++ )
		envp_add_back(&envp, envp_new(envl[i]));
	printf("what %s\n", envp->key);
	printf("AAAAAAAAAAAAAAAAA\n");
	data = set_path(envp);
	printf("what the fuck %s\n", data->path[0]);
}
