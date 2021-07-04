/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:43:05 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 07:58:14 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, t_len *len)
{
	char		*base;
	unsigned	n;

	base = "0123456789";
	n = 0;
	if (nb < 0)
	{
		n = (unsigned)nb * -1;
		nb *= -1;
		len->total++;
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putchar(base[n % 10]);
		len->total++;
	}
	else
	{
		ft_putchar(base[n % 10]);
		len->total++;
	}
}
