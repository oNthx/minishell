/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:17:19 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/13 03:35:40 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	index++;
	while (index--)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
	}
	return (0);
}
