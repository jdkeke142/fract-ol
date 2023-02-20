/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:21:58 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 19:10:31 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int	julia_const_enable(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	double			mouse_re;
	double			mouse_im;
	t_complex_pos	*pos;

	if (vars->fractal.type != FR_JULIA || keycode != MOUSE_RIGHT)
		return (0);
	pos = &vars->complex_pos;
	vars->mouse_pressed = 1;
	mouse_re = mouse_x / (WINDOW_HEIGHT / (pos->re_end
				- pos->re_start)) + pos->re_start;
	mouse_im = mouse_y / (WINDOW_WIDTH / (pos->im_end
				- pos->im_start)) + pos->im_start;
	vars->julia_const[0] = mouse_re;
	vars->julia_const[1] = mouse_im;
	return (1);
}

int	julia_const_disable(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	(void) mouse_x;
	(void) mouse_y;
	if (vars->fractal.type != FR_JULIA || keycode != MOUSE_RIGHT)
		return (0);
	vars->mouse_pressed = 0;
	return (0);
}

int	julia_const(int mouse_x, int mouse_y, t_vars *vars)
{
	double			mouse_re;
	double			mouse_im;
	double			re_abs;
	double			im_abs;
	t_complex_pos	*pos;

	if (vars->fractal.type != FR_JULIA || !vars->mouse_pressed)
		return (0);
	pos = &vars->complex_pos;
	mouse_re = mouse_x / (WINDOW_HEIGHT / (pos->re_end
				- pos->re_start)) + pos->re_start;
	mouse_im = mouse_y / (WINDOW_WIDTH / (pos->im_end
				- pos->im_start)) + pos->im_start;
	re_abs = vars->julia_const[0] - mouse_re;
	if (re_abs < 0)
		re_abs = -re_abs;
	im_abs = vars->julia_const[1] - mouse_im;
	if (im_abs < 0)
		im_abs = -im_abs;
	if (im_abs < JULIA_STEP && re_abs < JULIA_STEP)
		return (0);
	vars->julia_const[0] = mouse_re;
	vars->julia_const[1] = mouse_im;
	plot_fractal(vars);
	return (0);
}
