/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:11:58 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:11:59 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	jndex;

	jndex = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && jndex < len)
	{
		index = 0;
		while (needle[index] && haystack[index] == needle[index]
			&& ((jndex + index) < len))
			index++;
		if (!needle[index])
			return ((char *)haystack);
		jndex++;
		haystack++;
	}
	return (0);
}
