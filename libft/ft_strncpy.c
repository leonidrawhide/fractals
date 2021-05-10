/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:16:56 by apidgeot          #+#    #+#             */
/*   Updated: 2020/07/29 19:17:00 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char		*dp;
	const char	*sp;

	dp = (char*)dest;
	sp = (const char*)src;
	while (*sp != '\0' && len-- > 0)
		*dp++ = *sp++;
	if (len > 0 && *sp == '\0')
	{
		while (len-- > 0 && *dp)
			*dp++ = '\0';
	}
	return (dest);
}
