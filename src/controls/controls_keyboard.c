/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:10:59 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 23:37:01 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "fractals.h"

#ifndef ITERATION_STEP
# define ITERATION_STEP	5
#endif

#ifndef MOVE_STEP
# define MOVE_STEP	0.1
#endif

#ifndef ANGLE_STEP
# define ANGLE_STEP	10
#endif

#ifndef ANGLE_MAX
# define ANGLE_MAX 360
#endif

#ifndef ITERATION_MIN
# define ITERATION_MIN	15
#endif

#ifndef ITERATION_MAX
# define ITERATION_MAX	150
#endif

int	switch_fractal(int keycode, t_vars *vars)
{
	t_fractal_type	fractal_type;

	if (keycode != KEY_FRACTAL_MANDELBROT && keycode != KEY_FRACTAL_JULIA
		&& keycode != KEY_FRACTAL_TRICORN && keycode != KEY_FRACTAL_BURNINGSHIP)
		return (0);
	if (keycode == KEY_FRACTAL_JULIA)
		fractal_type = FR_JULIA;
	else if (keycode == KEY_FRACTAL_TRICORN)
		fractal_type = FR_TRICORN;
	else if (keycode == KEY_FRACTAL_BURNINGSHIP)
		fractal_type = FR_BURNINGSHIP;
	else
		fractal_type = FR_MANDELBROT;
	vars->fractal = get_fractal(fractal_type);
	vars->complex_pos = vars->fractal.complex_pos;
	vars->zoom_factor = ZOOM_FACTOR;
	vars->angle = 0;
	return (1);
}

int	switch_palette(int keycode, t_vars *vars)
{
	if (keycode != KEY_SWITCH_PALETTE)
		return (0);
	if (vars->color_hue == 360)
		vars->color_hue = HUE_FACTOR;
	else
		vars->color_hue += HUE_FACTOR;
	return (1);
}

int	change_iteration(int keycode, t_vars *vars)
{
	if (keycode != KEY_INCREASE_ITERATION && keycode != KEY_DECREASE_ITERATION)
		return (0);
	if (keycode == KEY_INCREASE_ITERATION)
	{
		if (vars->max_iteration + ITERATION_STEP > ITERATION_MAX)
			return (0);
		vars->max_iteration += ITERATION_STEP;
	}
	else
	{
		if (vars->max_iteration - ITERATION_STEP < ITERATION_MIN)
			return (0);
		vars->max_iteration -= ITERATION_STEP;
	}
	return (1);
}

int	move(int keycode, t_vars *vars)
{
	double	move_factor;

	if (keycode != KEY_MOVE_UP && keycode != KEY_MOVE_DOWN
		&& keycode != KEY_MOVE_RIGHT && keycode != KEY_MOVE_LEFT)
		return (0);
	move_factor = MOVE_STEP / vars->zoom_factor;
	if (keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_UP)
		move_factor = -move_factor;
	if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN)
	{
		vars->complex_pos.im_start += move_factor;
		vars->complex_pos.im_end += move_factor;
	}
	else
	{
		vars->complex_pos.re_start += move_factor;
		vars->complex_pos.re_end += move_factor;
	}
	return (1);
}

int	rotate(int keycode, t_vars *vars)
{
	if (keycode != KEY_ROTATE)
		return (0);
	if (vars->angle == ANGLE_MAX)
		vars->angle = 0;
	vars->angle += ANGLE_STEP;
	return (1);
}
