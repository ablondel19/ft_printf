/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 07:03:39 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 10:37:59 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dpad(int n, char c, t_len *len)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(c);
		len->total++;
	}
}

void	ft_lpad_d_one(t_f *ad, t_len *len)
{
	int i;

	i = 0;
	if (ad->z_pad && ad->neg)
	{
		ft_putchar('-');
		ad->z_val = 1;
	}
	while (i++ < ad->pad_val)
	{
		if (ad->z_pad)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len->total++;
	}
}

void	ft_lpad_d_two(t_f *ad, t_len *len)
{
	int i;

	i = 0;
	if (ad->z_pad && ad->neg && (!(ad->p_val >= 0 && ad->p_val <= ad->len)))
	{
		ft_putchar('-');
		ad->z_val = 1;
	}
	while (i++ < ad->pad_val)
	{
		if (ad->z_pad && (!(ad->p_val >= 0 && ad->p_val <= ad->len)))
			ft_putchar('0');
		else
			ft_putchar(' ');
		len->total++;
	}
}
