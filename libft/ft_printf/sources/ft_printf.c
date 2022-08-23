/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:00:36 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:00:39 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_controller(char ch, va_list list, int *ret_val)
{
	if (ch == 'c')
		ft_putchar(va_arg(list, int), ret_val);
	else if (ch == 's')
		ft_putstr(va_arg(list, char *), ret_val);
	else if (ch == 'd' || ch == 'i')
		ft_abs(va_arg(list, int), ret_val);
	else if (ch == 'u')
		ft_convert(va_arg(list, unsigned int), "0123456789", ret_val);
	else if (ch == 'x')
		ft_convert(va_arg(list, unsigned int),
			"0123456789abcdef", ret_val);
	else if (ch == 'X')
		ft_convert(va_arg(list, unsigned int),
			"0123456789ABCDEF", ret_val);
	else if (ch == 'p')
	{
		ft_putstr("0x", ret_val);
		ft_convert(va_arg(list, unsigned long), "0123456789abcdef", ret_val);
	}
	else if (ch == '%')
		ft_putchar('%', ret_val);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		is_empty;
	int		ret_val;

	ret_val = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			is_empty = 0;
			while (*(++str) == 32)
				is_empty = 1;
			if (is_empty)
				ft_putchar(' ', &ret_val);
			if (ft_controller(*str, list, &ret_val) != 0)
				ret_val += write(1, str, 1);
		}
		else
			ret_val += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (ret_val);
}
