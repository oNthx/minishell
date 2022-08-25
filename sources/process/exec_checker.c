/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:38:16 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/24 23:57:13 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	init(char ***list, char **path, char *p)
{
	*list = ft_split(p, ':');
	*path = 0;
	return (-1);
}

char	*get_fulltpath(char *path, char *name)
{
	int		i;
	char	*tmp;
	char	**list;
	char	*fullpath;
	int		access_res;

	if (!name || !*name)
		return (0);
	i = init(&list, &fullpath, path);
	access_res = access(name, F_OK);
	if (!access_res)
		fillpath = ft_strdup(name);
	while (list[++i] && access_res)
	{
		free(fullpath);
		tmp = ft_strjoin(tmp, name);
		free(tmp);
		access_res = access(fullpath, F_OK);
	}
	free_split(list);
	if (!access_res && !access(fullpath, X_OK))
		return (fullpath);
	free(fullpath);
	return (0);
}
