/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:36:06 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 22:54:44 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "fract_ol.h"

# ifndef BAILOUT_RADIUS
#  define BAILOUT_RADIUS	1000
# endif

double		fractal_iteration(t_vars *vars, double x, double y);
t_fractal	get_fractal(t_fractal_type fractal_type);
char		*get_fractal_name(t_fractal_type fractal_type);

#endif
