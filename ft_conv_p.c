/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:01:09 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 11:36:43 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_p(t_f *ad, unsigned long n)
{
	ad->len = ft_hexlen(n);
	ad->pad_val = ad->w_val - ad->len - 2;
}

void	ft_lpad_p(t_f *ad, unsigned long n, t_len *len)
{
	int i;

	i = 0;
	while (i++ < ad->pad_val)
	{
		ft_putchar(' ');
		len->total++;
	}
	write(1, "0x", 2);
	ft_putaddr(n, len);
}

void	ft_rpad_p(t_f *ad, unsigned long n, t_len *len)
{
	int i;

	i = 0;
	write(1, "0x", 2);
	ft_putaddr(n, len);
	while (i++ < ad->pad_val)
	{
		ft_putchar(' ');
		len->total++;
	}
}

int		ft_conv_p(va_list ap, char *flag, t_len *len)
{
	t_f				*ad;
	unsigned long	n;

	ad = NULL;
	if (!(ad = (t_f*)malloc(sizeof(t_f))))
		return (-1);
	ft_init(ad);
	ad = ft_flag_read(ap, ad, flag);
	if (ft_limit(ad->w_val))
	{
		free(ad);
		return (-1);
	}
	n = va_arg(ap, unsigned long);
	ft_update_p(ad, n);
	len->total = len->total + 2;
	if (ad->l_pad)
		ft_lpad_p(ad, n, len);
	else
		ft_rpad_p(ad, n, len);
	free(ad);
	return (0);
}
