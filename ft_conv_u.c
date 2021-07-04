/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:28:13 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 11:33:31 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_u(t_f *ad, unsigned n)
{
	ad->val = n;
	ad->len = ft_nbulen(n);
	if (ad->l_pad || ad->r_pad || ad->z_pad)
		ad->pad_val = ad->w_val - ft_nbulen(n);
	if (n < 0)
		ad->neg = 1;
	if (ad->p_val > ad->len)
	{
		ad->zs_val = ad->p_val - ad->len + ad->neg;
		ad->sz_val = ad->w_val - ad->p_val - ad->neg;
	}
	if (ad->neg && ad->p_val == ad->len)
	{
		ad->zs_val += 1;
		ad->sz_val = ad->w_val - ad->p_val - ad->neg;
		ad->pad_val -= 1;
	}
}

void	ft_lpad_u(t_f *ad, int n, t_len *len)
{
	int i;

	i = 0;
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
		ft_putu(n, len);
}

void	ft_rpad_u(t_f *ad, int n, t_len *len)
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
		ft_putu(n, len);
	if (ad->sz_val)
		ft_print_dpad(ad->sz_val, ' ', len);
	if (ad->zs_val == 0 && ad->sz_val == 0)
		ft_print_dpad(ad->pad_val, ' ', len);
}

int		ft_conv_u(va_list ap, char *flag, t_len *len)
{
	t_f			*ad;
	unsigned	n;

	ad = NULL;
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
	ft_update_u(ad, n);
	if (ad->l_pad)
		ft_lpad_u(ad, n, len);
	else if (ad->r_pad)
		ft_rpad_u(ad, n, len);
	free(ad);
	return (0);
}
