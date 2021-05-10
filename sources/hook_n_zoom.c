/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_n_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:10:09 by khelen            #+#    #+#             */
/*   Updated: 2020/08/09 14:14:04 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom(t_fractal *data, double zoomfactor)
{
	data->min.re = data->min.re / zoomfactor;
	data->min.im = data->min.im / zoomfactor;
	data->max.re = data->max.re / zoomfactor;
	data->max.im = data->max.im / zoomfactor;
}

int		mouse_hook(int mousecode, int x, int y, t_fractal *data)
{
	x = y;
	if (mousecode == 5)
	{
		zoom(data, 1.03);
		data->zoom += 0.03;
	}
	if (mousecode == 4)
	{
		zoom(data, 0.97);
		data->zoom -= 0.03;
	}
	print_fractol(data);
	return (0);
}

void	hooks_and_params(t_fractal *data)
{
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), red_butt, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 6, 0, julia_motion, data);
	mlx_loop(data->mlx_ptr);
}
