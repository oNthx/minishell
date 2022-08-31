/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:20:15 by bozgur            #+#    #+#             */
/*   Updated: 2022/03/31 06:19:32 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	writed;

	writed = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		writed += write(1, str++, 1);
	return (writed);
}

int	ft_putnbr(int n)
{
	int		sign;
	char	result[11];
	int		index;
	int		writed;

	writed = 0;
	index = 0;
	sign = (n >= 0) * 2 - 1;
	if (!n)
		writed += write(1, "0", 1);
	if (n < 0)
		writed += write(1, "-", 1);
	while (n)
	{
		result[index++] = n % 10 * sign + '0';
		n /= 10;
	}
	while (index--)
		writed += write(1, &result[index], 1);
	return (writed);
}

int	ft_putnbr_base(size_t n, int c)
{
	char	*base;
	int		writed;

	writed = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
		writed = ft_putnbr_base(n / 16, c);
	return (write(1, &base[n % 16], 1) + writed);
}

int	ft_putptr(size_t n)
{
	int	writed;

	writed = 0;
	if (n > 15)
		writed = ft_putptr(n / 16);
	return (write(1, &"0123456789abcdef"[n % 16], 1) + writed);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	result[20];
	int		index;
	int		writed;

	index = 0;
	if (!n)
		return (write(1, "0", 1));
	while (n)
	{
		result[index++] = n % 10 + '0';
		n /= 10;
	}
	writed = index;
	while (index--)
		write(1, &result[index], 1);
	return (writed);
}
