/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:20:12 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 23:01:34 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	mandelbrot_iteration(double *x0, double *y0, int max_iteration)
{
	double	x;
	double	y;
	double	x_temp;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (x * x + y * y <= BAILOUT_RADIUS && i < max_iteration)
	{
		x_temp = x * x - y * y + *x0;
		y = 2 * x * y + *y0;
		x = x_temp;
		i += 1;
	}
	*x0 = x;
	*y0 = y;
	return (i);
}
