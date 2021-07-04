/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:02:58 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/23 19:35:40 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_len
{
	int total;
}				t_len;

typedef struct	s_format
{
	int			val;
	int			neg;
	int			len;
	int			z_pad;
	int			z_val;
	int			l_pad;
	int			r_pad;
	int			pad_val;
	int			sz_val;
	int			zs_val;
	int			w_ispec;
	int			w_sign;
	int			w_val;
	int			p_ispec;
	int			p_sign;
	int			p_val;
}				t_f;

int				ft_conv_c(va_list ap, char *flag, t_len *len, char a);
int				ft_conv_s(va_list ap, char *flag, t_len *len);
int				ft_conv_p(va_list ap, char *flag, t_len *len);
int				ft_conv_d(va_list ap, char *flag, t_len *len);
int				ft_conv_u(va_list ap, char *flag, t_len *len);
int				ft_conv_x(va_list ap, char *flag, t_len *len);
t_f				*ft_flag_read(va_list ap, t_f *ad, char *flag);
void			ft_putchar(unsigned char c);
void			ft_putstr(char *s, t_len *len, t_f *ad);
void			ft_putaddr(unsigned long n, t_len *len);
void			ft_putnbr(int n, t_len *len);
void			ft_hex(unsigned n, char c, t_len *len);
void			ft_putu(unsigned n, t_len *len);
void			ft_print_dpad(int n, char c, t_len *len);
void			ft_lpad_d_one(t_f *ad, t_len *len);
void			ft_lpad_d_two(t_f *ad, t_len *len);
t_f				*ft_flag_read(va_list ap, t_f *ad, char *flag);
int				ft_select(va_list ap, char *flag, t_len *len);
void			ft_init(t_f *ad);
int				ft_atoi(char *s);
char			*ft_flagdup(const char *src);
char			*ft_strdup(const char *s1);
int				ft_strlen(char *s);
int				ft_nbrlen(int n);
int				ft_hexlen(unsigned long n);
int				ft_nbulen(unsigned n);
int				ft_limit(int n);
int				ft_conv_type(char c);
int				ft_printf(const char *s, ...);

#endif
