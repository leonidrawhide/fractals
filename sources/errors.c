/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:10:23 by khelen            #+#    #+#             */
/*   Updated: 2020/08/07 14:12:03 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		red_butt(t_fractal *data)
{
	free(data);
	exit(0);
}

void	error_and_free(t_fractal *data)
{
	ft_putstr("Error\n");
	free(data);
	exit(0);
}
