/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:09:51 by khelen            #+#    #+#             */
/*   Updated: 2020/08/09 14:19:45 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		is_key(int key)
{
	return (key == 69 || key == 15 || key == 53 ||
			key == 83 || key == 84 || key == 85 ||
			key == 4 || key == 5 || key == 78);
}

void	do_key(int key, t_fractal *data)
{
	if (key == 15 || key == 17)
		change_variation(key, data);
	if (key == 78 || key == 69)
		change_iter(key, data);
	if (key == 53)
		red_butt(data);
	if (key == 125)
		data->moveX += (0.12 / pow(data->zoom, 2));
	if (key == 126)
		data->moveX -= (0.12 / pow(data->zoom, 2));
	if (key == 124)
		data->moveY -= (0.12 / pow(data->zoom, 2));
	if (key == 123)
		data->moveY += (0.12 / pow(data->zoom, 2));
	if (key == 27)
	{
		zoom(data, 0.97);
		data->zoom -= 0.03;
	}
	if (key == 24)
	{
		zoom(data, 1.03);
		data->zoom += 0.03;
	}
}

int		deal_key(int key, t_fractal *data)
{
	is_key(key);
	do_key(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_fractol(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_fractal *data;

	if (ac >= 2 && av[1] != NULL)
	{
		if (!(check_fctl(av[1])))
		{
			ft_putstr("Wrong! Use mandelbrot, julia or burningship.\n");
			return (0);
		}
		if (!(data = (t_fractal*)malloc(sizeof(t_fractal) + 1)))
		{
			free(data);
			ft_putstr("Error! Memory for data was not allocated.\n");
			exit(0);
		}
		data->fractol_number = check_fctl(av[1]);
		default_params(data);
		data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->img_d = (int *)mlx_get_data_addr(data->mlx_img, &data->bpp,
											&data->size_l, &data->endian);
		print_fractol(data);
		hooks_and_params(data);
	}
	ft_putstr("Argument error! Use mandelbrot, julia or burningship.\n");
	return (0);
}
