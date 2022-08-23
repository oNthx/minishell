/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:10:11 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:10:13 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*res;

	len = 0;
	index = 0;
	while (s1[len])
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (res);
	while (*s1)
		res[index++] = *s1++;
	res[index] = '\0';
	return (res);
}
