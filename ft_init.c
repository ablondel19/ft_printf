/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:08:48 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 21:46:44 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_f *ad)
{
	ad->val = 0;
	ad->neg = 0;
	ad->len = 0;
	ad->z_pad = 0;
	ad->z_val = 0;
	ad->l_pad = 0;
	ad->r_pad = 0;
	ad->pad_val = 0;
	ad->sz_val = 0;
	ad->zs_val = 0;
	ad->w_ispec = 0;
	ad->w_sign = 0;
	ad->w_val = 0;
	ad->p_ispec = 0;
	ad->p_sign = 0;
	ad->p_val = 0;
}
