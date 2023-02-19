/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:10:59 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/17 18:33:47 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int	switch_fractal(int keycode, t_vars *vars)
{
	t_fractal_type	fractal_type;

	if (keycode == KEY_FRACTAL_MANDELBROT || keycode == KEY_FRACTAL_JULIA
		|| keycode == KEY_FRACTAL_TRICORN || keycode == KEY_FRACTAL_BURNINGSHIP)
	{
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
		return (1);
	}
	return (0);
}

int	switch_palette(int keycode, t_vars *vars)
{
	if (keycode != KEY_SWITCH_PALETTE)
		return (0);
	if (vars->palette_index == vars->palettes.palettes_count - 1)
		vars->palette_index = 0;
	else
		vars->palette_index += 1;
	return (1);
}

int	reset_pos(int keycode, t_vars *vars)
{
	if (keycode != KEY_RESET_POS)
		return (0);
	vars->complex_pos = get_fractal(vars->fractal.type).complex_pos;
	return (1);
}

int	change_iteration(int keycode, t_vars *vars)
{
	if (keycode == KEY_INCREASE_ITERATION)
	{
		if (vars->max_iteration + ITERATION_STEP > ITERATION_MAX)
			return (0);
		vars->max_iteration += ITERATION_STEP;
		return (1);
	}
	if (keycode == KEY_DECREASE_ITERATION)
	{
		if (vars->max_iteration - ITERATION_STEP < ITERATION_MIN)
			return (0);
		vars->max_iteration -= ITERATION_STEP;
		return (1);
	}
	vars->complex_pos = get_fractal(vars->fractal.type).complex_pos;
	return (0);
}
