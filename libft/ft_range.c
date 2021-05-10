/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:09:36 by apidgeot          #+#    #+#             */
/*   Updated: 2020/07/29 19:09:40 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int n;
	int *arr;

	n = 0;
	if (max <= min)
		return (0);
	arr = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		arr[n] = min;
		n++;
		min++;
	}
	return (arr);
}
