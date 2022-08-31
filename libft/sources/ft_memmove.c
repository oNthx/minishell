/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:17:11 by bozgur            #+#    #+#             */
/*   Updated: 2022/02/07 19:19:35 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_1;
	const char	*src_1;

	dst_1 = (char *)dst;
	src_1 = (const char *)src;
	if (!dst && !src)
		return (0);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
		while (len--)
			dst_1[len] = src_1[len];
	return (dst);
}
