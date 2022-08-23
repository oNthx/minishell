/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:01:59 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:02:00 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			index;
	void			*result;
	unsigned char	*temp;

	index = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	temp = (unsigned char *)result;
	while (index < (count * size))
		temp[index++] = 0;
	return (result);
}
