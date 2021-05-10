/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:10:17 by khelen            #+#    #+#             */
/*   Updated: 2020/08/07 15:43:27 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		initialization(t_fractal *data)
{
	data->factor = init_complex(
		(data->max.re - data->min.re) / (WIDTH - 1),
		(data->max.im - data->min.im) / (HEIGHT - 1));
}

void		color(t_fractal *data)
{
	if (data->iter < data->max_iter)
		data->color = (data->iter % 8 + 1) * 10000 / 2;
	else
		data->color = 0;
	data->img_d[data->x * WIDTH + data->y] = data->color * data->vrtn;
	data->x++;
}

t_complex	init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		change_iter(int key, t_fractal *data)
{
	if (key == 69)
		data->max_iter += 20;
	if (key == 78 && data->max_iter >= 10)
		data->max_iter -= 20;
}

void		change_variation(int key, t_fractal *data)
{
	if (key == 17)
		data->vrtn += 100;
	if (key == 15 && data->vrtn >= 100)
		data->vrtn -= 100;
}
