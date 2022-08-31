/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:20:22 by bozgur            #+#    #+#             */
/*   Updated: 2022/03/31 06:19:42 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putstr(char *str);
int	get_ptrr(size_t n);
int	ft_putnbr(int n);
int	ft_putnbr_base(size_t n, int c);
int	ft_printf(const char *prm, ...);
int	get_after_percent(const char prm, va_list ptr);
int	get_after_percent_vol_two(const char prm, va_list ptr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putptr(size_t n);

#endif
