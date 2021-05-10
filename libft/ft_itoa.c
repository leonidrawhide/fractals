/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:01:18 by apidgeot          #+#    #+#             */
/*   Updated: 2020/07/29 19:01:23 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	k;
	char			*str;

	i = ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		k = -n;
		str[0] = '-';
	}
	else
		k = n;
	while (k > 9)
	{
		str[i--] = (k % 10) + '0';
		k /= 10;
	}
	str[i] = (k % 10) + '0';
	return (str);
}
