/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:36:06 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/17 17:03:11 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <math.h>

# ifndef ITERATION_STEP
#  define ITERATION_STEP	5
# endif

# ifndef ITERATION_MIN
#  define ITERATION_MIN	15
# endif

# ifndef ITERATION_MAX
#  define ITERATION_MAX	150
# endif

# ifndef BAILOUT_RADIUS
#  define BAILOUT_RADIUS	1000
# endif

typedef enum e_fractal_type
{
	FR_MANDELBROT,
	FR_JULIA,
	FR_BURNINGSHIP,
	FR_TRICORN
}			t_fractal_type;

typedef struct s_complex_pos
{
	double			re_start;
	double			re_end;
	double			im_start;
	double			im_end;
}				t_complex_pos;

typedef struct s_fractal
{
	t_fractal_type	type;
	t_complex_pos	complex_pos;
}				t_fractal;

double		fractal_iteration(t_fractal *fractal, double pos[2],
				double julia_const[2], int max_iteration);
t_fractal	get_fractal(t_fractal_type fractal_type);

#endif
