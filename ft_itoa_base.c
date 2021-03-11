/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulkazan <yulkazan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:58:36 by yulkazan          #+#    #+#             */
/*   Updated: 2021/03/04 17:47:34 by yulkazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(size_t value, size_t base)
{
	if (value >= base)
		return (ft_itoa_len(value / base, base) + 1);
	else
		return (1);
}

static void	ft_itoa_result(size_t v, size_t b, char *str, size_t l)
{
	size_t	tmp;

	while (l > 0)
	{
		tmp = v % b;
		if (tmp >= 10)
			tmp = tmp + 7;
		str[l - 1] = tmp + '0';
		v /= b;
		l--;
	}
}

char		*ft_itoa_base(size_t value, int base)
{
	int		len;
	char	*str;

	len = ft_itoa_len(value, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_itoa_result(value, base, str, len);
	str[len] = '\0';
	return (str);
}
