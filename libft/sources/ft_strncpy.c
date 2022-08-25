/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:13:14 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/24 14:13:14 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (!n || !src)
		return (0);
	while (*src && idx < n)
		dst[idx++] = *src++;
	while (idx <= n)
		dst[idx++] = 0;
	return (dst);
}
