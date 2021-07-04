/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:29:24 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 07:57:37 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu(unsigned n, t_len *len)
{
	char *base;

	base = "0123456789";
	if (n >= 10)
	{
		ft_putu(n / 10, len);
		ft_putchar(base[n % 10]);
		len->total++;
	}
	else
	{
		ft_putchar(base[n % 10]);
		len->total++;
	}
}
