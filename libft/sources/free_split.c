/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:13:36 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/24 14:13:37 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **line)
{
	int	idx;

	idx = 0;
	while (line[idx])
		free(line[idx++]);
	free(line);
}