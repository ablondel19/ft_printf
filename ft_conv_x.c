/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:05:36 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 11:36:40 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_x(t_f *ad, unsigned n)
{
	ad->val = n;
	ad->len = ft_hexlen(n);
	if (ad->l_pad || ad->r_pad || ad->z_pad)
		ad->pad_val = ad->w_val - ft_hexlen(n);
	if (n < 0)
		ad->neg = 1;
	if (ad->p_val > ad->len)
	{
		ad->zs_val = ad->p_val - ad->len + ad->neg;
		ad->sz_val = ad->w_val - ad->p_val - ad->neg;
	}
}

void	ft_lpad_x(t_f *ad, int n, t_len *len, char c)
{
	if (!ad->p_ispec)
		ft_lpad_d_one(ad, len);
	else if (ad->sz_val == 0 && ad->zs_val == 0)
		ft_lpad_d_two(ad, len);
	if (ad->sz_val)
		ft_print_dpad(ad->sz_val, ' ', len);
	if (ad->zs_val)
		ft_print_dpad(ad->zs_val, '0', len);
	if (n == 0 && ad->p_ispec && ad->p_val == 0)
	{
		if (!ad->w_val)
			return ;
		write(1, " ", 1);
		len->total++;
	}
	else
	{
		if (c == 'x')
			ft_hex(n, 'x', len);
		else
			ft_hex(n, 'X', len);
	}
}

void	ft_rpad_x(t_f *ad, int n, t_len *len, char c)
{
	if (ad->zs_val)
		ft_print_dpad(ad->zs_val, '0', len);
	if (n == 0 && ad->p_ispec && ad->p_val == 0)
	{
		if (!ad->w_val)
			return ;
		write(1, " ", 1);
		len->total++;
	}
	else
	{
		if (c == 'x')
			ft_hex(n, 'x', len);
		else
			ft_hex(n, 'X', len);
	}
	if (ad->sz_val)
		ft_print_dpad(ad->sz_val, ' ', len);
	if (ad->zs_val == 0 && ad->sz_val == 0)
		ft_print_dpad(ad->pad_val, ' ', len);
}

int		ft_conv_x(va_list ap, char *flag, t_len *len)
{
	t_f			*ad;
	char		c;
	unsigned	n;

	ad = NULL;
	c = flag[ft_strlen(flag) - 1];
	if (!(ad = (t_f*)malloc(sizeof(t_f))))
		return (-1);
	ft_init(ad);
	ad = ft_flag_read(ap, ad, flag);
	if (ft_limit(ad->w_val) || ft_limit(ad->p_val))
	{
		free(ad);
		return (-1);
	}
	n = va_arg(ap, unsigned);
	ft_update_x(ad, n);
	if (ad->l_pad)
		ft_lpad_x(ad, n, len, c);
	else
		ft_rpad_x(ad, n, len, c);
	free(ad);
	return (0);
}
