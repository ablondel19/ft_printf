/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:50:42 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 07:58:38 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned n, char c, t_len *len)
{
	char *base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hex(n / 16, c, len);
		ft_putchar(base[n % 16]);
		len->total++;
	}
	else
	{
		ft_putchar(base[n % 16]);
		len->total++;
	}
}
