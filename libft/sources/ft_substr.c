/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:03:08 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/29 03:34:29 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		size;
	char		*str;

	size = 0;
	if (!s || !len || ft_strlen(s) <= start)
		return (ft_strdup(""));
	while (s[start + size] && size < len)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	size = 0;
	while (s[start] && size < len)
		str[size++] = s[start++];
	str[size] = 0;
	return (str);
}
