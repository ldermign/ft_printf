/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/10 21:47:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_s(va_list ap, t_flag_len *flag)
{
    char *arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, flag);
}

void    conv_c(va_list ap, t_flag_len *flag)
{
    char cara;

    cara = va_arg(ap, int);
    ft_putchar(cara, flag);
}

void    conv_per(t_flag_len *flag)
{
    ft_putstr("\%", flag);
}

void    conv_d_i(va_list ap, t_flag_len *flag)
{
    int 	arg_int;
	char	*temp;

    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	ft_putstr(temp, flag);
	free(temp);
}

void    conv_u(va_list ap, t_flag_len *flag)
{
    unsigned int 	arg_unsdint;

    arg_unsdint = va_arg(ap, unsigned int);
	ft_putnbr(arg_unsdint, flag);
}

void	conv_x_X(char c, va_list ap, t_flag_len *len)
{
	unsigned int	arg_unsdint;
	char			*base;

	arg_unsdint = va_arg(ap, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base_printf(arg_unsdint, base, len);
}

void    conv_p(va_list ap, t_flag_len *flag)
{
	// va_arg = type void ?
	// utiliser unsdint ?
	// c la meme que u mais avec 0x au debut ptdr ????
	// base de 16 ??????????????????????????/
	unsigned int 	arg_unsdint;

    arg_unsdint = va_arg(ap, unsigned int);
	ft_putstr("0x", flag);
	ft_putnbr(arg_unsdint, flag);
}