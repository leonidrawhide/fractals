/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:09:58 by khelen            #+#    #+#             */
/*   Updated: 2020/08/09 13:00:02 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_fractal *data)
{
	initialization(data);
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->c.im = data->max.im - data->y * data->factor.im + data->moveY;
		data->x = 0;
		while (data->x < WIDTH)
		{
			data->c.re = data->min.re + data->x * data->factor.re + data->moveX;
			data->z = init_complex(data->c.re, data->c.im);
			data->iter = 0;
			while (pow(data->z.re, 2.0) + pow(data->z.im, 2.0) <= 4 &&
												data->iter < data->max_iter)
				print_julia(data);
			color(data);
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	print_menu(data);
}

int		julia_motion(int x, int y, t_fractal *data)
{
	data->k = init_complex(4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	init(data);
	return (0);
}

void	print_julia(t_fractal *data)
{
	data->z = init_complex(pow(data->z.re, 2.0) - pow(data->z.im, 2.0)
			+ data->k.re, 2.0 * data->z.re * data->z.im + data->k.im);
	data->iter++;
}
