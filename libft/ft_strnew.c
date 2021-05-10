/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:17:22 by apidgeot          #+#    #+#             */
/*   Updated: 2020/07/29 19:17:25 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*i;
	unsigned int	n;

	if (size + 1 == 0)
		return (NULL);
	if (!(i = (char*)malloc(size + 1)))
		return (NULL);
	n = (unsigned int)size;
	ft_bzero(i, size);
	i[n] = '\0';
	return (i);
}
