/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/18 15:14:28 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_conv(char c, t_flag_len *flag)
{
	if (c == 'c')
		flag->conv_c = 1;
	if (c == 's')
		flag->conv_s = 1;
	if (c == 'p')
		flag->conv_p = 1;
	if (c == 'd' || c == 'i')
		flag->conv_d_i = 1;
	if (c == 'u')
		flag->conv_u = 1;
	if (c == 'x' || c == 'X')
		flag->conv_x = 1;
	if (c == '%')
		flag->conv_per = 1;
}

int		which_conv(const char *str, va_list ap, t_flag_len *flag)
{
	flag_width(flag);
	flag_precision(flag);
	ft_struct_conv(*str, flag);
	if (flag->conv_c == 1)
		conv_c(ap, flag);
	else if (flag->conv_s == 1)
		conv_s(ap, flag);
	else if (flag->conv_p == 1)
		conv_p(ap, flag);
	else if (flag->conv_d_i == 1)
		conv_d_i(ap, flag);
	else if (flag->conv_u == 1)
		conv_u(ap, flag);
	else if (flag->conv_x == 1)
		conv_x_X(*str, ap, flag);
	else if (flag->conv_per == 1)
		conv_per(flag);
	if (flag->str_width != NULL)
		free(flag->str_width);
	if (flag->str_precision != NULL)
		free(flag->str_precision);
	if (flag->final_str_flag != NULL)
		free(flag->final_str_flag);
	return (1);
}

int		chaipas(const char *str, va_list ap)
{
	t_flag_len	flag;
	int			i;

	i = 0;
	flag.final_len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ++i)
		{
			i += which_flag(&str[i], ap, &flag);
			if (ft_is_conv(str[i]))
				i += which_conv(&str[i], ap, &flag);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &flag);
			i++;
		}
	}
	return (flag.final_len);
}

int		ft_printf(const char *str, ...)
{
	int			final_length;

	va_list ap;

	va_start(ap, str);
	final_length = chaipas(str, ap);
	va_end(ap);
	return (final_length);
}

void	check_printf(int size_ft_printf, int size_printf)
{
	if (size_ft_printf == size_printf)
		printf(KGRN"OK\n");
	else
		printf(KRED"KO\n");
}

int		main()
{
	// int				test_d_i = -8372;
	// unsigned int	test_u = 42;
	// unsigned int	test_x_X = 420;
	// char 			*test_s = "pouet c'est relou";
	// char			test_c = 'q';
	// int				test_adresse_p = 9999999;
	// int				*test_p = &test_adresse_p;

	// printf(KCYN"\t\t//!\\\\MON PRINTF//!\\\\\n");
	// printf(KGRE"Taille pour test d/i = %d.\n", ft_printf(KCYN"Quelque chose d --------------> [d : %15d].\n", test_d_i));
	// printf(KGRE"Taille pour test c = %d.\n", ft_printf(KCYN"Quelque chose c --------------> [%c].\n", test_c));
	// printf(KGRE"Taille pour test s = %d.\n", ft_printf(KCYN"Quelque chose s --------------> [%s].\n", test_s));
	// printf(KGRE"Taille pour test p = %d.\n", ft_printf(KCYN"Quelque chose p --------------> [%p].\n", test_p));
	// printf(KGRE"Taille pour test d/i = %d.\n", ft_printf(KCYN"Quelque chose d & i ----------> [d : %8.3d] & [i : %i].\n", test_d_i, test_d_i));
	// printf(KGRE"Taille pour test u = %d.\n", ft_printf(KCYN"Quelque chose u --------------> [%u].\n", test_u));
	// printf(KGRE"Taille pour test x et X = %d.\n", ft_printf(KCYN"Quelque chose x & X ----------> [x : %x] & [X : %X].\n", test_x_X, test_x_X));
	// printf(KGRE"Taille pour test percent = %d.\n", ft_printf(KCYN"Quelque chose percent --------> [%%].\n"));
	// printf(KGRN"\n\t\t//!\\\\VRAI PRINTF//!\\\\\n");
	// printf(KGRE"Taille pour test d/i = %d.\n", printf(KGRN"Quelque chose d --------------> [d : %15d].\n", test_d_i));
	// printf(KGRE"Taille pour test c = %d.\n", printf(KGRN"Quelque chose c --------------> [%c].\n", test_c));
	// printf(KGRE"Taille pour test s = %d.\n", printf(KGRN"Quelque chose s --------------> [%s].\n", test_s));
	// printf(KGRE"Taille pour test p = %d.\n", printf(KGRN"Quelque chose p --------------> [%p].\n", test_p));
	// printf(KGRE"Taille pour test d/i = %d.\n", printf(KGRN"Quelque chose d & i ----------> [d : %8.3d] & [i : %i].\n", test_d_i, test_d_i));
	// printf(KGRE"Taille pour test u = %d.\n", printf(KGRN"Quelque chose u --------------> [%u].\n", test_u));
	// printf(KGRE"Taille pour test x et X = %d.\n", printf(KGRN"Quelque chose x & X ----------> [x : %x] & [X : %X].\n", test_x_X, test_x_X));
	// printf(KGRE"Taille pour test percent = %d.\n", ft_printf(KGRN"Quelque chose percent --------> [%%].\n"));

	//test flags


	unsigned int	test_u = 42;
	unsigned int	test_x_X = 666666;
	char 			*test_s = "pouet c'est relou";
	char				test_c = 'q';
	int				test_adresse_p = 9999999;
	int				*test_p = &test_adresse_p;
	int test1 = 765;
	int test2 = -765;
	int size_ft_printf;
	int size_printf;
	// d


	size_printf = printf(KGRN"c [10] -------> [%*c].\n", 10, test_c);
	size_ft_printf = ft_printf(KCYN"c [10] -------> [%*c].\n", 10, test_c);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"c [-10] ------> [%-*c].\n", 10, test_c);
	size_ft_printf = ft_printf(KCYN"c [-10] ------> [%-*c].\n", 10, test_c);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"s [30.10] -------> [%*.*s].\n", 30, 11, test_s);
	size_ft_printf = ft_printf(KCYN"s [30.10] -------> [%*.*s].\n", 30, 11, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [-30.10] ------> [%-*.*s].\n", 30, 11, test_s);
	size_ft_printf = ft_printf(KCYN"s [-30.10] ------> [%-*.*s].\n", 30, 11, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [10.30] -------> [%*.*s].\n", 11, 30, test_s);
	size_ft_printf = ft_printf(KCYN"s [10.30] -------> [%*.*s].\n", 11, 30, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [-10.30] ------> [%-*.*s].\n", 11, 30, test_s);
	size_ft_printf = ft_printf(KCYN"s [-10.30] ------> [%-*.*s].\n", 11, 30, test_s);
	check_printf(size_ft_printf, size_printf);


	size_printf = printf(KGRN"p [30] -------> [%*.p].\n", 30, test_p);
	size_ft_printf = ft_printf(KCYN"p [30] -------> [%*.p].\n", 30, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [-30] ------> [%-*p].\n", 30, test_p);
	size_ft_printf = ft_printf(KCYN"p [-30] ------> [%-*p].\n", 30, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [6] -------> [%*p].\n", 6, test_p);
	size_ft_printf = ft_printf(KCYN"p [6] -------> [%*p].\n", 6, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [-6] ------> [%-*p].\n", 6, test_p);
	size_ft_printf = ft_printf(KCYN"p [-6] ------> [%-*p].\n", 6, test_p);
	check_printf(size_ft_printf, size_printf);




	
	size_printf = printf(KGRN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);

///////////////////////////////////////////////////////////////

	size_printf = printf(KGRN"positif [10] -------> [d : %*.1d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [10] -------> [d : %*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [10] -------> [d : %*.1d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [10] -------> [d : %*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10] ------> [d : %-*d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10] ------> [d : %-*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);





	size_printf = printf(KGRN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010] ------> [d : %0*d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [010] ------> [d : %0*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [010] ------> [d : %0*d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [010] ------> [d : %0*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);

/////////////////////////////////////////////////////////////////////////







	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);


/////////////////////////////////////////////////////////////////




	size_printf = printf(KGRN"percent [10] ----------> [percent : %10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [10] ----------> [percent : %10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-10] ---------> [percent : %-10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-10] ---------> [percent : %-10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [010] ---------> [percent : %010%].\n");
	size_ft_printf = ft_printf(KCYN"percent [010] ---------> [percent : %010%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [2] -----------> [percent : %2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [2] -----------> [percent : %2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-2] ----------> [percent : %-2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-2] ----------> [percent : %-2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [02] ----------> [percent : %02%].\n");
	size_ft_printf = ft_printf(KCYN"percent [02] ----------> [percent : %02%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [20] ----------> [percent : %20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [20] ----------> [percent : %20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-20] ---------> [percent : %-20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-20] ---------> [percent : %-20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [020] ---------> [percent : %020%].\n");
	size_ft_printf = ft_printf(KCYN"percent [020] ---------> [percent : %020%].\n");
	check_printf(size_ft_printf, size_printf);




	size_printf = printf(KGRN"percent [10.20] ----------> [percent : %10.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [10.20] ----------> [percent : %10.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-10.20] ---------> [percent : %-10.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-10.20] ---------> [percent : %-10.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [010.20] ---------> [percent : %010.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [010.20] ---------> [percent : %010.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [2.2] -----------> [percent : %2.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [2.2] -----------> [percent : %2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-2.2] ----------> [percent : %-2.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-2.2] ----------> [percent : %-2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [02.2] ----------> [percent : %02.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [02.2] ----------> [percent : %02.2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [20.10] ----------> [percent : %20.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [20.10] ----------> [percent : %20.10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-20.10] ---------> [percent : %-20.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-20.10] ---------> [percent : %-20.10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [020.10] ---------> [percent : %020.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [020.10] ---------> [percent : %020.10%].\n");
	check_printf(size_ft_printf, size_printf);

   /////////////////////////////////////////////////////////////////


	size_printf = printf(KGRN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);

//////////////////////////////////////////////////////////












	
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [010.20] -------> [d : %0*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [010.20] -------> [d : %0*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [010.10] -------> [d : %0*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [010.10] -------> [d : %0*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// write (1, "\n", 1);



	// size_ft_printf = ft_printf(KCYN"negatif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test2);
	// size_printf = printf(KGRN"negatif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// 	size_ft_printf = ft_printf(KCYN"negatif [10] ----------> [d : %10d].\n", test2);
	// size_printf = printf(KGRN"negatif [10] ----------> [d : %10d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [01] -----------> [d : %01d].\n", test1);
	// size_printf = printf(KGRN"positif [01] -----------> [d : %01d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [01] -----------> [d : %01d].\n", test2);
	// size_printf = printf(KGRN"negatif [01] -----------> [d : %01d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-10] ----------> [d : %-10d].\n", test1);
	// size_printf = printf(KGRN"positif [-10] ----------> [d : %-10d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10] ----------> [d : %-10d].\n", test2);
	// size_printf = printf(KGRN"negatif [-10] ----------> [d : %-10d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-1] -----------> [d : %-1d].\n", test1);
	// size_printf = printf(KGRN"positif [-1] -----------> [d : %-1d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-1] -----------> [d : %-1d].\n", test2);
	// size_printf = printf(KGRN"negatif [-1] -----------> [d : %-1d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	
	return (0);
	}



	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [d : %*.*d].\n", 10, 20, test1);
	// size_printf = printf(KGRN"positif [10.20] -------> [d : %*.*d].\n", 10, 20, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [10.10] -------> [d : %*.*d].\n", 10, 10, test1);
	// size_printf = printf(KGRN"positif [10.10] -------> [d : %*.*d].\n", 10, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);

		// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [010.20] -------> [d : %0*.*d].\n", 10, 20, test1);
	// size_printf = printf(KGRN"positif [010.20] -------> [d : %0*.*d].\n", 10, 20, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [010.10] -------> [d : %0*.*d].\n", 10, 10, test1);
	// size_printf = printf(KGRN"positif [010.10] -------> [d : %0*.*d].\n", 10, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);

		// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test1);
	// size_printf = printf(KGRN"positif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test1);
	// size_printf = printf(KGRN"positif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);

	

	// size_ft_printf = ft_printf(KCYN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [10.10] -------> [d : %*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [10.10] -------> [d : %*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// write (1, "\n", 1);