/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:58:40 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/27 18:41:49 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pad_s(int n, t_len *len)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(' ');
		len->total++;
	}
}

void	ft_update_s(t_f *ad, char *tmp)
{
	ad->len = ft_strlen(tmp);
	if (ad->w_val >= ad->len)
		ad->pad_val = ad->w_val - ad->len;
	if (ad->p_val < ad->w_val && ad->len < ad->p_val)
		ad->pad_val = ad->w_val - ad->len;
	if (!ad->p_sign)
		if (ad->p_val)
			ad->len = ad->p_val;
	if (ad->p_ispec && !ad->p_val)
		ad->len = 0;
	if (ad->p_ispec && ad->p_val == 0)
		ad->pad_val = ad->w_val;
	if (ad->p_val > 0 && ad->p_val < ad->w_val)
		ad->pad_val = ad->w_val - ad->p_val;
}

void	ft_lpad_s(char *tmp, t_f *ad, t_len *len)
{
	if (ad->p_val > ft_strlen(tmp))
		ad->pad_val = ad->w_val - ft_strlen(tmp);
	ft_print_pad_s(ad->pad_val, len);
	ft_putstr(tmp, len, ad);
}

void	ft_rpad_s(char *tmp, t_f *ad, t_len *len)
{
	if (ad->p_val > ft_strlen(tmp))
		ad->pad_val = ad->w_val - ft_strlen(tmp);
	ft_putstr(tmp, len, ad);
	ft_print_pad_s(ad->pad_val, len);
}

int		ft_conv_s(va_list ap, char *flag, t_len *len)
{
	t_f		*ad;
	char	*tmp;

	ad = NULL;
	tmp = NULL;
	if (!(ad = (t_f*)malloc(sizeof(t_f))))
		return (-1);
	ft_init(ad);
	ft_flag_read(ap, ad, flag);
	if (ft_limit(ad->w_val) || ft_limit(ad->p_val))
	{
		free(ad);
		return (-1);
	}
	if (!(tmp = ft_strdup(va_arg(ap, const char*))))
		if (!(tmp = ft_strdup("(null)")))
			return (-1);
	ft_update_s(ad, tmp);
	if (ad->l_pad)
		ft_lpad_s(tmp, ad, len);
	else if (ad->r_pad)
		ft_rpad_s(tmp, ad, len);
	free(ad);
	free(tmp);
	return (0);
}
