/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:46:55 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 06:36:18 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(unsigned long n, t_len *len)
{
	char *base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putaddr(n / 16, len);
		ft_putchar(base[n % 16]);
		len->total++;
	}
	else
	{
		ft_putchar(base[n % 16]);
		len->total++;
	}
}
