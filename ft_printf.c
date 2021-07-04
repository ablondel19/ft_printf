/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:41:46 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/27 19:07:25 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_type(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}

int		ft_select(va_list ap, char *flag, t_len *len)
{
	char	c;
	int		n;

	n = 0;
	c = flag[ft_strlen(flag) - 1];
	if (c == 'c')
		n = ft_conv_c(ap, flag, len, '\0');
	else if (c == '%')
		n = ft_conv_c(ap, flag, len, '%');
	else if (c == 's')
		n = ft_conv_s(ap, flag, len);
	else if (c == 'p')
		n = ft_conv_p(ap, flag, len);
	else if ((c == 'd') || (c == 'i'))
		n = ft_conv_d(ap, flag, len);
	else if (c == 'u')
		n = ft_conv_u(ap, flag, len);
	else if ((c == 'x') || (c == 'X'))
		n = ft_conv_x(ap, flag, len);
	if (n == -1)
	{
		free(len);
		return (-1);
	}
	return (0);
}

int		ft_print(va_list ap, const char *s, t_len *len, int *i)
{
	int		j;
	char	*tmp;

	j = *i;
	tmp = NULL;
	if (s[j + 1] == '%')
	{
		ft_putchar('%');
		j++;
	}
	else
	{
		if (!(tmp = ft_flagdup(&s[j + 1])))
			return (-1);
		if (ft_select(ap, tmp, len) == -1)
		{
			free(tmp);
			return (-1);
		}
		j += ft_strlen(tmp);
		len->total--;
		free(tmp);
	}
	*i = j;
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	t_len	*len;
	int		i;
	int		total;

	i = -1;
	if ((!(len = (t_len*)malloc(sizeof(t_len)))) || !s)
		return (-1);
	va_start(ap, s);
	len->total = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (ft_print(ap, s, len, &i) == -1)
				return (-1);
		}
		else
			ft_putchar(s[i]);
		len->total++;
	}
	va_end(ap);
	total = len->total;
	free(len);
	return (total);
}
