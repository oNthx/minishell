/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:06:03 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:06:04 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_t;
	const unsigned char	*s2_t;

	if (!n)
		return (0);
	s1_t = (const unsigned char *)s1;
	s2_t = (const unsigned char *)s2;
	while (*s1_t++ == *s2_t++ && n - 1)
		n--;
	return (*--s1_t - *--s2_t);
}
