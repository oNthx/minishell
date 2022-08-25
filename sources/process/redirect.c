/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:06:50 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/25 00:10:42 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	red_read(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || dup2(fd, 0) == -1)
		return (ERROR);
	return (0);
}

int	red_write(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0 || dup2(fd, 1) == -1)
		return (ERROR);
	return (0);
}

int	red_overwrite(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd < 0 || dup2(fd, 1) == -1)
		return (ERROR);
	return (0);
}
