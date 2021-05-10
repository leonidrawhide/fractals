/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:14:22 by apidgeot          #+#    #+#             */
/*   Updated: 2020/08/09 13:34:39 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef	struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_fractal
{
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			x;
	int			y;
	int			fractol_number;
	int			iter;
	int			max_iter;
	int			vrtn;
	double		zoom;
	double		moveX;
	double		moveY;

	int			bpp;
	int			size_l;
	int			endian;
	int			*img_d;

	t_complex	min;
	t_complex	max;
	t_complex	factor;

	t_complex	c;
	t_complex	z;
	t_complex	k;
}				t_fractal;

void			init(t_fractal *data);
void			default_params(t_fractal *data);
void			julia(t_fractal *data);
void			print_julia(t_fractal *data);
void			print_burning_ship(t_fractal *data);
int				red_butt(t_fractal *data);
void			error_and_free(t_fractal *data);
t_complex		init_complex(double re, double im);
void			change_variation(int key, t_fractal *data);
void			change_iter(int key, t_fractal *data);
void			initialization(t_fractal *data);
void			color(t_fractal *data);
void			print_mandelbrot(t_fractal *data);
void			zoom(t_fractal *data, double zoomfactor);
int				julia_motion(int x, int y, t_fractal *data);
void			print_fractol(t_fractal *data);
void			print_menu(t_fractal *data);
int				check_fctl(char	*fctl);
int				deal_key(int key, t_fractal *data);
void			hooks_and_params(t_fractal *data);

#endif
