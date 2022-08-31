/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:42:18 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/27 15:07:09 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_1;
	const char	*src_1;

	dst_1 = (char *)dst;
	src_1 = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i++ < n)
		*dst_1++ = *src_1++;
	return (dst);
}
