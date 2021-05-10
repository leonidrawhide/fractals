/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:09:38 by khelen            #+#    #+#             */
/*   Updated: 2020/08/07 16:51:13 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	default_params(t_fractal *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT + 200,
		"FRACT'OL");
	data->min = init_complex(-2.0, -2.0);
	data->max.re = 2.0;
	data->max.im = data->min.im
		+ (data->max.re - data->min.re) * HEIGHT / WIDTH;
	data->vrtn = 10;
	data->k = init_complex(-0.4, 0.6);
	data->max_iter = 50;
	data->bpp = 32;
	data->endian = 1;
	data->size_l = WIDTH * 4;
	data->zoom = 1;
	data->moveY = 0;
	data->moveX = 0;
}

int		check_fctl(char *fctl)
{
	if (!ft_strncmp(fctl, "mandelbrot", 10))
		return (1);
	if (!ft_strncmp(fctl, "julia", 5))
		return (2);
	if (!ft_strncmp(fctl, "burningship", 11))
		return (3);
	return (0);
}

void	init(t_fractal *data)
{
	if (data->fractol_number == 1)
		print_mandelbrot(data);
	if (data->fractol_number == 2)
		julia(data);
	if (data->fractol_number == 3)
		print_burning_ship(data);
}

void	print_on_adress(char *s, int x, int y, t_fractal *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, y + 1, 0x000000, s);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFAFA, s);
}

void	print_menu(t_fractal *data)
{
	char *iterations;
	char *zoomchar;

	iterations = ft_itoa(data->max_iter);
	zoomchar = ft_itoa(data->zoom);
	print_on_adress("Zoom in/out:                        Scroll or +-",
														25, 1010, data);
	print_on_adress("Change color:                       R & T keys",
														25, 1040, data);
	print_on_adress("Change maximum iteration:           NUM +/-",
														25, 1070, data);
	print_on_adress("Move around:                        arrows",
														25, 1100, data);
	if (data->fractol_number == 2)
		print_on_adress("Change parameter of Julia:          Mouse move",
														25, 1130, data);
	print_on_adress("Iterations:", 550, 1010, data);
	if (data->max_iter > 0)
		print_on_adress(iterations, 670, 1010, data);
	else
		print_on_adress("none", 670, 1010, data);
	print_on_adress("Zoom:     ", 550, 1030, data);
	print_on_adress(zoomchar, 670, 1030, data);
	free(iterations);
	free(zoomchar);
}
