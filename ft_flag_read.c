/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:02:19 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 11:14:06 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_one(t_f *ad, char *flag, int *i)
{
	int j;

	j = *i;
	ad->r_pad = 1;
	ad->w_sign = 1;
	while (flag[j] && flag[j] == '-')
		j++;
	*i = j;
}

void	ft_flag_two(t_f *ad, char *flag, int *i)
{
	int j;

	j = *i;
	ad->z_pad = 1;
	if (ad->r_pad)
		ad->z_pad = 0;
	while (flag[j] && (flag[j] == '0' || flag[j] == '-'))
	{
		if (flag[j] == '-')
		{
			ad->r_pad = 1;
			ad->l_pad = 0;
			ad->z_pad = 0;
		}
		j++;
	}
	*i = j;
}

void	ft_flag_three(va_list ap, t_f *ad, int *i)
{
	ad->w_val = va_arg(ap, int);
	ad->w_ispec = 1;
	if (ad->w_val < 0)
	{
		ad->w_val *= -1;
		ad->w_sign = 1;
		ad->r_pad = 1;
		ad->l_pad = 0;
	}
	*i = *i + 1;
}

void	ft_flag_four(va_list ap, t_f *ad, char *flag, int i)
{
	if (flag[i] == '*' && !ad->w_val && !ad->w_ispec)
		ft_flag_three(ap, ad, &i);
	if (flag[i++] == '.')
		ad->p_ispec = 1;
	if (flag[i] >= '0' && flag[i] <= '9')
	{
		ad->p_val = ft_atoi(&flag[i]);
		i += ft_nbrlen(ft_atoi(&flag[i]));
	}
	else if (flag[i] == '*' && !ad->p_val)
	{
		ad->p_val = va_arg(ap, int);
		if (ad->p_val < 0)
			ad->p_sign = 1;
		i++;
	}
}

t_f		*ft_flag_read(va_list ap, t_f *ad, char *flag)
{
	int i;

	i = 0;
	if (flag[i] == '-')
		ft_flag_one(ad, flag, &i);
	else
		ad->l_pad = 1;
	if (flag[i] == '0')
		ft_flag_two(ad, flag, &i);
	if (flag[i] >= '0' && flag[i] <= '9')
	{
		ad->w_val = ft_atoi(&flag[i]);
		i += ft_nbrlen(ft_atoi(&flag[i]));
		ad->w_ispec = 1;
	}
	while (flag[i] && (flag[i] != '*' &&
	flag[i] != '.' && (!(flag[i] >= '0' && flag[i] <= '9'))))
		i++;
	ft_flag_four(ap, ad, flag, i);
	return (ad);
}
