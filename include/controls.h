/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:23 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:20 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "graphics.h"
# include "fractals.h"
# include <stdlib.h>

enum e_key_map
{
	KEY_INCREASE_ITERATION = 61,
	KEY_DECREASE_ITERATION = 45,
	KEY_MOVE_UP = 65362,
	KEY_MOVE_DOWN = 65364,
	KEY_MOVE_RIGHT = 65363,
	KEY_MOVE_LEFT = 65361,
	KEY_SWITCH_PALETTE = 99,
	KEY_FRACTAL_MANDELBROT = 49,
	KEY_FRACTAL_JULIA = 50,
	KEY_FRACTAL_TRICORN = 51,
	KEY_FRACTAL_BURNINGSHIP = 52,
	KEY_RESET_POS = 114,
	KEY_CLOSE = 65307,
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	MOUSE_DOWN = 4,
	MOUSE_UP = 5
};

# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR	1.1
# endif

# ifndef MOVE_FACTOR
#  define MOVE_FACTOR	0.1
# endif

int		handle_key_hooks(int keycode, t_vars *vars);
int		handle_mouse_hooks(int keycode, int mouse_x, int mouse_y, t_vars *vars);
int		julia_const_disable(int keycode, int mouse_x, int mouse_y,
			t_vars *vars);
int		julia_const(int mouse_x, int mouse_y, t_vars *vars);
int		destroy(t_vars *vars);

#endif
