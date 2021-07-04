/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:49:10 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/27 19:04:12 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_len *len, t_f *ad)
{
	int i;

	i = 0;
	if (s[0] == '\0' && ((!ad->p_ispec) || (ad->p_ispec && ad->p_val)))
	{
		if (ad->w_ispec)
		{
			ft_putchar(' ');
			len->total++;
		}
		return ;
	}
	while (s[i] && i < ad->len)
	{
		write(1, &s[i], 1);
		len->total++;
		i++;
	}
}
