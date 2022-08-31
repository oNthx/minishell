/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:20:00 by bozgur            #+#    #+#             */
/*   Updated: 2022/08/31 12:57:25 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <unistd.h>

int	combinate(const char prm, va_list ptr)
{
	size_t	argv;
	char	*str;

	if (prm == 's')
	{
		str = va_arg(ptr, char *);
		return (ft_putstr(str));
	}
	else if (prm == 'd' || prm == 'i')
	{
		argv = va_arg(ptr, int);
		return (ft_putnbr(argv));
	}
	else if (prm == 'x' || prm == 'X')
	{
		argv = va_arg(ptr, unsigned int);
		if (prm == 'x')
			return (ft_putnbr_base(argv, 'x'));
		else
			return (ft_putnbr_base(argv, 'X'));
	}
	return (0);
}

int	combinate2(const char prm, va_list ptr)
{
	int					argv;
	void				*addr;
	unsigned int		uarg;
	long int			xaddr;

	if (prm == 'c')
	{
		argv = va_arg(ptr, int);
		return (write(1, &argv, 1));
	}
	else if (prm == 'p')
	{
		addr = va_arg(ptr, void *);
		xaddr = (long int)addr;
		return (write(1, "0x", 2) + ft_putptr(xaddr));
	}
	else if (prm == 'u')
	{
		uarg = va_arg(ptr, unsigned int);
		return (ft_putnbr_unsigned(uarg));
	}
	else if (prm == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *prm, ...)
{
	va_list			ptr;
	int				res;

	res = 0;
	va_start(ptr, prm);
	while (*prm)
	{
		if (*prm == '%')
		{
			prm++;
			while (*prm == ' ')
				prm++;
			res += combinate(*prm, ptr)
				+ combinate2(*prm, ptr);
		}
		else
			res += write(1, prm, 1);
		prm++;
	}
	return (res);
}
