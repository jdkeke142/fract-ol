/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:13:03 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 23:26:58 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <math.h>

int	mandelbrot_iteration(double *x0, double *y0, int max_iteration);
int	julia_iteration(double *x0_ptr, double *y0_ptr, t_vars *vars);
int	tricorn_iteration(double *x0, double *y0, int max_iteration);
int	burningship_iteration(double *x0, double *y0, int max_iteration);

double	normalize_iterations(double x, double y, double i, int max_iteration)
{
	if (i < max_iteration)
		i = i + 1 - (log((log(x * x + y * y) / 2) / log(2)) / log(2));
	return (i);
}

double	fractal_stability(double normalized_i, int max_iteration)
{
	double	value;

	value = normalized_i / max_iteration;
	return (fmax(0.0, fmin(value, 1.0)));
}

double	fractal_iteration(t_vars *vars, double x, double y)
{
	int		i;
	double	radians;
	double	x_temp;

	i = 0;
	radians = vars->angle * (M_PI / 180);
	x_temp = x * cos(radians) - y * sin(radians);
	y = x * sin(radians) + y * cos(radians);
	x = x_temp;
	if (vars->fractal.type == FR_JULIA)
		i = julia_iteration(&x, &y, vars);
	else if (vars->fractal.type == FR_TRICORN)
		i = tricorn_iteration(&x, &y, vars->max_iteration);
	else if (vars->fractal.type == FR_BURNINGSHIP)
		i = burningship_iteration(&x, &y, vars->max_iteration);
	else
		i = mandelbrot_iteration(&x, &y, vars->max_iteration);
	return (fractal_stability(normalize_iterations(x, y, i,
				vars->max_iteration), vars->max_iteration));
}

t_fractal	get_fractal(t_fractal_type fractal_type)
{
	t_complex_pos	complex_pos;

	if (fractal_type == FR_JULIA)
		complex_pos = ((t_complex_pos){-2.1, 1.8, -1.4, 1.3});
	else if (fractal_type == FR_TRICORN)
		complex_pos = ((t_complex_pos){-3, 2.4, -1.8, 1.8});
	else if (fractal_type == FR_BURNINGSHIP)
		complex_pos = ((t_complex_pos){-2.2, 1.4, -1.8, 0.6});
	else
		complex_pos = ((t_complex_pos){-2.5, 1.2, -1.2, 1.2});
	return ((t_fractal){fractal_type, complex_pos});
}

char	*get_fractal_name(t_fractal_type fractal_type)
{
	if (fractal_type == FR_JULIA)
		return ("Julia");
	if (fractal_type == FR_TRICORN)
		return ("Tricorn");
	if (fractal_type == FR_BURNINGSHIP)
		return ("Burning Ship");
	return ("Mandelbrot");
}
