/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:29:44 by ablondel          #+#    #+#             */
/*   Updated: 2020/12/22 11:03:48 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_len(const char *src)
{
	int i;

	i = 0;
	while (src[i] && !ft_conv_type(src[i]))
		i++;
	return (i);
}

char	*ft_flagdup(const char *src)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char) * (flag_len(src) + 1));
	if (!dst)
		return (NULL);
	while (src[i] && i <= flag_len(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
