/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:00:54 by bozgur            #+#    #+#             */
/*   Updated: 2022/07/31 03:00:55 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, int *ret_val);
void	ft_putstr(char *str, int *ret_val);
size_t	ft_strlen(const char *str);
void	ft_convert(size_t num, char *repres, int *ret_val);
int		ft_printf(const char *str, ...);
void	ft_abs(int data, int *ret_val);

#endif
