/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:04:25 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/16 16:08:04 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		n = 0;
		while (needle[n] && haystack[n] == needle[n] && n + i < len)
			n++;
		if (!needle[n])
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
