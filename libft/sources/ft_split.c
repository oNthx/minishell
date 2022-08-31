/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:16:11 by bozgur            #+#    #+#             */
/*   Updated: 2022/06/30 21:53:46 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		count += !!*s;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		index;
	int		count;
	int		rescount;

	rescount = 0;
	index = 0;
	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (rescount < word_count(s, c))
	{
		count = 0;
		while (s[index] && s[index] == c)
			index++;
		while (s[index] && s[index] != c)
		{
			index++;
			count++;
		}
		result[rescount++] = ft_substr(s, index - count, count);
	}
	result[rescount] = 0;
	return (result);
}
