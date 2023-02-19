/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:25:36 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/19 17:15:02 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_fractal_pixel(t_vars *vars, t_data *img, double x, double y)
{
	double		iteration_count;
	double		hue;
	double		saturation;
	t_rgb		rgb_color;
	t_palette	palette;

	iteration_count = fractal_iteration(&vars->fractal, (double [2])
		{vars->complex_pos.re_start + (x / WINDOW_HEIGHT)
			* (vars->complex_pos.re_end - vars->complex_pos.re_start),
			vars->complex_pos.im_start + (y / WINDOW_WIDTH)
			* (vars->complex_pos.im_end - vars->complex_pos.im_start)},
			vars->julia_const, vars->max_iteration);
	palette = vars->palettes.palettes[vars->palette_index];
	if (iteration_count == 1)
	{
		my_mlx_pixel_put(img, x, y, create_trgb(0, 0, 0, 0));
		return ;
	}
	hue = (iteration_count * 360) + palette.base_hue;
	saturation = fmin(1, iteration_count + palette.saturation_modifier);
	rgb_color = hsv_to_rgb(hue, saturation, 1.0);
	my_mlx_pixel_put(img, x, y,
		create_trgb(0, rgb_color.r, rgb_color.g, rgb_color.b));
}

void	plot_fractal(t_vars *vars)
{
	double	x;
	double	y;

	x = 0;
	while (x < WINDOW_HEIGHT)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			plot_fractal_pixel(vars, &vars->img, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
