/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_delimeter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:00:16 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/25 00:06:24 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	nonext(char *buf, int pipes[2], int readed)
{
	char	*buf2;

	buf2 = ft_strjoin(buf, "\n");
	write(pipes[1], buf2, readed + 1);
	free(buf2);
}

static void	reconnect(int std_in)
{
	dup2(std_in, 0);
	close(std_in);
	connectsignals();
}

static int	next(char *buf, t_list *del, int readed)
{
	return (!ft_strcmp(buf, (char *)del->content),
			readed - (readed > 1) && readed);
}

int	red_delimeter(t_list *del, int read_red)
{
	char	*buf;
	int		std_in;
	int		pipes[2];

	if (!read_red && pipe(pipes))
		return (ERROR);
	std_in = dup(0);
	signal(SIGINT, del_handler);
	while (1)
	{
		buf = readline("> ");
		if (next(buf, del, ft_strlen(buf)))
		{
			if (!del->next)
				break ;
			del = del->next;
		}
		else if (ft_strlen(buf) > 0 && !del->next && !read_red)
			nonext(buf, pipes, ft_strlen(buf));
	}
	reconnect(std_in);
	if (close(pipes[1]) || dup2(pipes[0], 0) == -1)
		return (ERROR);
	return (0);
}
