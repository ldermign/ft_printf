/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:36:41 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/23 13:45:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flip_zero_and_space(t_flag_len *flag)
{
	int		i;
	size_t	here;
	size_t	size;
	char	swap;

	i = 0;
	here = 0;
	size = flag->size_final_str_flag;
	while (flag->final_str_flag[here + 1] && (here < flag->size_final_str_flag))
	{
		here++;
		if (flag->final_str_flag[here] != flag->final_str_flag[here + 1])
			break ;
	}
	if (size > here && here > 0)
	{
		size--;
		if (flag->final_str_flag[0] == '-')
			i++;
		if (flag->final_str_flag[size] == '\0')
			size--;
		while (size > here && flag->final_str_flag[size] != '\0')
		{
			swap = flag->final_str_flag[size];
			flag->final_str_flag[size] = flag->final_str_flag[i];
			flag->final_str_flag[i] = swap;
			size--;
			i++;
		}
	}
}

void	width_sup(t_flag_len *flag)
{
	int i;
	int j;
	int max;
	int min;

	i = 0;
	j = 0;
	max = flag->nbr_width;
	min = flag->nbr_precision;
	// printf()
	while (i < (max - min))
	{
		flag->final_str_flag[i] = flag->str_width[i];
		i++;
	}
	while (i < max)
	{
		flag->final_str_flag[i] = flag->str_precision[j];
		i++;
		j++;
	}
	flag->final_str_flag[i] = '\0';
}

void	precision_sup_or_equal_width(t_flag_len *flag)
{
	int i;
	int size;

	i = 0;
	size = flag->nbr_precision;
	while (i < size)
	{
		flag->final_str_flag[i] = flag->str_precision[i];
		i++;
	}
	flag->final_str_flag[i] = '\0';
}

void	join_str_width_and_precision(t_flag_len *flag)
{
	int size;
	
	size = 0;
	if (flag->width == 1 || flag->precision == 1)
	{
		if (flag->nbr_precision >= flag->nbr_width)
			size = flag->nbr_precision;
		else
			size = flag->nbr_width;
		if ((flag->final_str_flag = malloc(sizeof(char) * (size + 1))) == NULL)
			return ;
	}
	if (flag->width == 1 && flag->precision == 1)
	{
		// printf("pouet\n");
		if (flag->nbr_precision >= flag->nbr_width)
			precision_sup_or_equal_width(flag);
		else
			width_sup(flag);
	}
	// if (flag->width == 1 && flag->precision == -1)
	// if (flag->padded_zero == 1 && flag->precision == -1 && flag->minus == 1)
		// ft_fill_with_c(flag->final_str_flag, ' ', size + 1);
	// else if (flag->precision == 1 && flag->width == -1)
	// if (flag->padded_zero == 1 && flag->precision == -1 && flag->minus == 0)
		// ft_fill_with_c(flag->final_str_flag, '0', size + 1);
	// printf("padded_zero = {%d}, precision = {%d}, width = {%d}, minus = {%d}\n", flag->padded_zero, flag->precision, flag->width, flag->minus);
	if (flag->width == 1 && flag->precision == -1 && flag->padded_zero == 0)
	{
		ft_fill_with_c(flag->final_str_flag, ' ', size + 1);
		// printf("test\n");
	}
	else if ((flag->precision == 1 && flag->width == -1)
	|| (flag->padded_zero == 1 && flag->precision == -1))
		ft_fill_with_c(flag->final_str_flag, '0', size + 1);
	flag->size_final_str_flag = ft_strlen(flag->final_str_flag);
	if (flag->minus == 1)
		flip_zero_and_space(flag);
}