/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:55:07 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/23 14:45:27 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_c(t_f *ad, t_len *len)
{
	ad->pad_val = ad->w_val - 1;
	len->total += ad->pad_val;
	len->total += 2;
	if (ad->w_val)
		len->total--;
}

void	ft_lpad_c(t_f *ad, char c)
{
	int i;

	i = 0;
	while (i++ < ad->pad_val)
	{
		if (c == '%' && ad->z_pad)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	ft_putchar(c);
}

void	ft_rpad_c(t_f *ad, char c)
{
	int i;

	i = 0;
	ft_putchar(c);
	while (i++ < ad->pad_val)
	{
		if (c == '%' && ad->z_pad)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

int		ft_conv_c(va_list ap, char *flag, t_len *len, char a)
{
	t_f		*ad;
	char	c;

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
	if (a == '%')
		c = a;
	else
		c = va_arg(ap, int);
	ft_update_c(ad, len);
	if (ad->l_pad)
		ft_lpad_c(ad, c);
	else
		ft_rpad_c(ad, c);
	free(ad);
	return (0);
}
