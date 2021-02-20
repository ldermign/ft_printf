/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:01:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/20 12:02:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	return (c == '-' || c == '*' || c == '.' || (c >= '0' && c <= '9'));
}

int		ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
	|| c == 'x' || c == 'X' || c == '%');
}

int 	ft_is_width(char c)
{
	return ((c >= '0' && c <= '9') || c == '.' || c == '*');
}

int		ft_is_all(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
	|| c == 'x' || c == 'X' || c == '-' || c == '*' || c == '.' || c == '%'
	|| (c >= '0' && c <= '9'));
}

int		ft_no_flag(t_flag_len *flag)
{
	if (flag->minus == 0 && flag->padded_zero == 0 && flag->precision == -1
	&& flag->width == -1)
		return (1);
	return (0);
}