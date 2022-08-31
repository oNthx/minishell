/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:49:09 by bozgur            #+#    #+#             */
/*   Updated: 2022/02/23 03:22:56 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	len = 0;
	while (*s1)
		str[len++] = *s1++;
	str[len] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s && s[index])
	{
		if (s[index] == ((char)c))
			return ((char *)s + index);
		index++;
	}
	if (s && s[index] == (char)c)
		return ((char *)(s + index));
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	index;
	size_t	result;

	index = 0;
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (dstsize + ft_strlen(src));
	result = d_len + ft_strlen(src);
	while (src[index] && d_len < dstsize - 1)
		dst[d_len++] = src[index++];
	dst[d_len] = 0;
	return (result);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*result;
	int		len;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (ft_strdup(""));
		if (!s1)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	*result = 0;
	ft_strlcat(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
