/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:25:38 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/19 12:53:35 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "colors.h"
# include "fractals.h"
# include "ft_string.h"
# include "ft_stdio.h"
# include "mlx.h"

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1366
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 768
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_fractal		fractal;
	t_complex_pos	complex_pos;
	t_palette_set	palettes;
	t_data			img;
	double			julia_const[2];
	int				max_iteration;
	int				palette_index;
	int				mouse_pressed;
}				t_vars;

void	plot_fractal(t_vars *vars);
void	init_graphics(t_fractal_type fractal_type);

#endif
