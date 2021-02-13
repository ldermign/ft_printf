/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/13 16:05:51 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>


/*
**	TEJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
*/

#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // VERT


# include <libc.h> /////////////////////////////////////////////////////////////


#define ERR(FILE, FUNC, LINE) printf(KYEL"%s:%s:%d\033[0m", FILE, FUNC, LINE)


int				ft_printf(const char *str, ...);

/*
**	Structures cspdiuxX%
*/

typedef	struct	s_struct
{
	int final_len;
	int minus;
	int padded_zero;
	int width;
	int precision;
	int	nbr_width;
	int nbr_precision;
	char *str_of_flag;
}				t_flag_len;
void			ft_init_flag_len_flag(t_flag_len *flag);


/*
**	Checks
*/

int				ft_check_flag(const char *str);
int				ft_is_flag(char c);
int				ft_is_digit(char c);
int				ft_is_conv(char c);
int				ft_is_width(char c); //largeur
int				ft_is_all(char c);

/*
**	Utils
*/

void			ft_putchar(char c, t_flag_len *len);
void			ft_putstr(char *str, t_flag_len *len);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int nb);
char			*ft_itoa_base(size_t nb, char *base);
void			ft_putnbr_base_printf(long nbr, char *base, t_flag_len *len);
char			*ft_strcat(char *dst, char *src);
char			*ft_strncat(char *dst, char *src, size_t nb);
void			ft_putnbr(unsigned int nbr, t_flag_len *len);
void			ft_putnbr_adr(unsigned long nbr, t_flag_len *len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_rev_string(char *str, int size);
int				ft_atoi_printf(char *str);
void			*ft_memmove(char *dst, char *src, size_t n);
void			*fill_from_end(char *dst, char *src, size_t n);
int				ft_atoi(char *str);

/*
**	Flags
*/

char			*to_flag(char *str, va_list ap, t_flag_len *flag);
int				which_flag(const char *str, t_flag_len *ntm);
// void			flag_minus(va_list ap, t_flag_len *ntm);
// void			flag_padded_zero(va_list ap, t_flag_len *ntm);
// void			flag_width(va_list ap, t_flag_len *ntm);
// void			flag_precision(va_list ap, t_flag_len *ntm);

/*
**	Conversion
*/

int				which_conv(const char *str, va_list ap, t_flag_len *ntm);
void			conv_d_i(char *str_flag, va_list ap, t_flag_len *flag);
void			conv_s(char *str_flag, va_list ap, t_flag_len *flag);
void			conv_c(char *str_flag, va_list ap, t_flag_len *flag);
void			conv_u(char *str_flag, va_list ap, t_flag_len *flag);
void			conv_per(char *str_flag, t_flag_len *flag);
void			conv_x_X(char *str_flag, char c, va_list ap, t_flag_len *len);
void			conv_p(char *str_flag, va_list ap, t_flag_len *flag);






void    ft_printf_monuq(t_flag_len ntm);





#endif
