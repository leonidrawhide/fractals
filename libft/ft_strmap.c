/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:15:36 by apidgeot          #+#    #+#             */
/*   Updated: 2020/07/29 19:15:40 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ptr;
	char *res;

	if (s == NULL || !(res = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	ptr = res;
	while (*s)
		*ptr++ = (f(*s++));
	return (res);
}
