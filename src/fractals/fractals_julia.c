/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:20:10 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/17 16:31:11 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	julia_iteration(double *x0_ptr, double *y0_ptr, double julia_const[2],
	int max_iteration)
{
	double	x_temp;
	int		i;
	double	x0;
	double	y0;

	i = 0;
	x0 = *x0_ptr;
	y0 = *y0_ptr;
	while (x0 * x0 + y0 * y0 <= BAILOUT_RADIUS && i < max_iteration)
	{
		x_temp = x0 * x0 - y0 * y0 + julia_const[0];
		y0 = 2 * x0 * y0 + julia_const[1];
		x0 = x_temp;
		i += 1;
	}
	*x0_ptr = x0;
	*y0_ptr = y0;
	return (i);
}
