/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:59:35 by bozgur            #+#    #+#             */
/*   Updated: 2022/06/30 21:52:57 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *s, char *n)
{
	char	swap;

	swap = *s;
	*s = *n;
	*n = swap;
}

void	ft_reverse(char *s)
{
	int		len;
	int		index;
	int		count;

	index = *s == '-';
	len = ft_strlen(s);
	count = len / 2;
	while (count--)
		ft_swap(s + index++, s + --len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		index;
	int		sign;

	index = 0;
	sign = 1 - (n < 0) * 2;
	if (!n)
		return (ft_strdup("0"));
	result = (char *)malloc((11) * sizeof(char));
	if (!result)
		return (0);
	*result = (sign < 0 && !index++) * '-';
	while (n)
	{
		result[index++] = n % 10 * sign + '0';
		n /= 10;
	}
	result[index] = 0;
	ft_reverse(result);
	return (result);
}
