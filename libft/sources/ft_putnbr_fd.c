/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:42:53 by bozgur            #+#    #+#             */
/*   Updated: 2022/02/03 11:08:15 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		index;
	char	result[11];

	index = 0;
	sign = (n >= 0) * 2 - 1;
	if (!n)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	while (n)
	{
		result[index++] = n % 10 * sign + '0';
		n /= 10;
	}
	while (index--)
		write(fd, &result[index], 1);
}
