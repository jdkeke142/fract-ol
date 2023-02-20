/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:20:10 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 22:56:23 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	julia_iteration(double *x0_ptr, double *y0_ptr, t_vars *vars)
{
	double	x_temp;
	int		i;
	double	x0;
	double	y0;

	i = 0;
	x0 = *x0_ptr;
	y0 = *y0_ptr;
	while (x0 * x0 + y0 * y0 <= BAILOUT_RADIUS && i < vars->max_iteration)
	{
		x_temp = x0 * x0 - y0 * y0 + vars->julia_re;
		y0 = 2 * x0 * y0 + vars->julia_im;
		x0 = x_temp;
		i += 1;
	}
	*x0_ptr = x0;
	*y0_ptr = y0;
	return (i);
}
