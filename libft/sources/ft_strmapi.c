/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 06:18:38 by bozgur            #+#    #+#             */
/*   Updated: 2022/01/31 16:41:10 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		index;

	index = 0;
	if (!s || !f)
		return (0);
	new = ft_strdup(s);
	if (!new)
		return (0);
	while (*s)
	{
		new[index] = f(index, *s++);
		index++;
	}
	return (new);
}
