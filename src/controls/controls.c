/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:58:42 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/17 17:16:04 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int	julia_const_enable(int keycode, int mouse_x, int mouse_y, t_vars *vars);
int	julia_const_disable(int keycode, int mouse_x, int mouse_y, t_vars *vars);
int	julia_const(int mouse_x, int mouse_y, t_vars *vars);
int	switch_fractal(int keycode, t_vars *vars);
int	switch_palette(int keycode, t_vars *vars);
int	reset_pos(int keycode, t_vars *vars);
int	change_iteration(int keycode, t_vars *vars);
int	zoom(int keycode, int mouse_x, int mouse_y, t_vars *vars);
int	move(int keycode, int mouse_x, int mouse_y, t_vars *vars);

int	destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	handle_mouse_hooks(int keycode, int mouse_x, int mouse_y, t_vars *vars)
{
	if (julia_const_enable(keycode, mouse_x, mouse_y, vars)
		|| zoom(keycode, mouse_x, mouse_y, vars)
		|| move(keycode, mouse_x, mouse_y, vars))
		plot_fractal(vars);
	return (0);
}

int	handle_key_hooks(int keycode, t_vars *vars)
{
	if (keycode == KEY_CLOSE)
		destroy(vars);
	if (switch_fractal(keycode, vars)
		|| switch_palette(keycode, vars)
		|| reset_pos(keycode, vars)
		|| change_iteration(keycode, vars))
		plot_fractal(vars);
	return (0);
}
