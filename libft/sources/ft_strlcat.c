/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:30:09 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/27 22:11:33 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	index;
	size_t	t_size;

	d_len = 0;
	index = 0;
	while (dst[d_len])
		d_len++;
	if (dstsize <= d_len)
		return (dstsize + ft_strlen(src));
	t_size = d_len + ft_strlen(src);
	while (src[index] && d_len < dstsize - 1)
		dst[d_len++] = src[index++];
	dst[d_len] = '\0';
	return (t_size);
}
