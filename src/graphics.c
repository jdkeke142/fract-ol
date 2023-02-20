/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:25:36 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 18:02:11 by kjimenez         ###   ########.fr       */
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

void	print_help(t_vars *vars)
{
	ft_printf("\e[1;1H\e[2J");
	ft_printf("%s%s\n\nControls%s\n", BOLD, UNDERLINE, RESET);
	ft_printf("%sZoom up & down: Mouse up & mouse down\n", BOLD);
	ft_printf("Recenter view: Left Click somewhere in the window\n");
	ft_printf("Move view: Arrows keys\n");
	ft_printf("Reset view: R key\n");
	ft_printf("Increase & decrease iteration: + and - keys\n");
	ft_printf("Rotate color palette: C key\n");
	ft_printf("Change fractal type: 1-4 keys\n");
	ft_printf("Change julia constants: Hold Right Click\n");
	ft_printf("\n%sInformations%s\n", UNDERLINE, RESET);
	ft_printf("%sCurrent fractal: %s\n", BOLD,
		get_fractal_name(vars->fractal.type));
	ft_printf("Current max iterations: %d\n", vars->max_iteration);
	ft_printf("Current color palette: %d%s\n", vars->palette_index, RESET);
}
