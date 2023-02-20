/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:25:00 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 23:34:48 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "graphics.h"
#include "fractals.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	zoom(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	double			interpolation;
	double			mouse_re;
	double			mouse_im;
	t_complex_pos	*pos;

	if (keycode != KEY_ZOOM_UP && keycode != KEY_ZOOM_DOWN)
		return (0);
	pos = &vars->complex_pos;
	interpolation = 1;
	mouse_re = mouse_x / (WINDOW_HEIGHT / (pos->re_end
				- pos->re_start)) + pos->re_start;
	mouse_im = mouse_y / (WINDOW_WIDTH / (pos->im_end
				- pos->im_start)) + pos->im_start;
	if (keycode == KEY_ZOOM_DOWN)
		interpolation = 1.0 / ZOOM_FACTOR;
	else if (keycode == KEY_ZOOM_UP)
		interpolation = ZOOM_FACTOR / 1.0;
	pos->re_start = interpolate(mouse_re, pos->re_start, interpolation);
	pos->im_start = interpolate(mouse_im, pos->im_start, interpolation);
	pos->re_end = interpolate(mouse_re, pos->re_end, interpolation);
	pos->im_end = interpolate(mouse_im, pos->im_end, interpolation);
	vars->zoom_factor /= interpolation;
	return (1);
}

int	recenter(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	double			mouse_re;
	double			mouse_im;
	double			re_center;
	double			im_center;
	t_complex_pos	*pos;

	if (keycode != KEY_RECENTER)
		return (0);
	pos = &vars->complex_pos;
	mouse_re = mouse_x / (WINDOW_HEIGHT / (pos->re_end
				- pos->re_start)) + pos->re_start;
	mouse_im = mouse_y / (WINDOW_WIDTH / (pos->im_end
				- pos->im_start)) + pos->im_start;
	re_center = mouse_re - ((pos->re_start + pos->re_end) / 2);
	im_center = mouse_im - ((pos->im_start + pos->im_end) / 2);
	pos->re_start = pos->re_start + re_center;
	pos->re_end = pos->re_end + re_center;
	pos->im_start = pos->im_start + im_center;
	pos->im_end = pos->im_end + im_center;
	return (1);
}

int	reset_pos(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	(void) mouse_x;
	(void) mouse_y;
	if (keycode != KEY_RESET_POS)
		return (0);
	vars->complex_pos = get_fractal(vars->fractal.type).complex_pos;
	vars->zoom_factor = ZOOM_FACTOR;
	vars->angle = 0;
	return (1);
}
