/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:25:38 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 18:28:30 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "colors.h"
# include "fractals.h"
# include "ft_string.h"
# include "ft_stdio.h"
# include "mlx.h"

# ifndef RESET
#  define RESET "\x1B[0m"
# endif

# ifndef BOLD
#  define BOLD "\x1B[1m"
# endif

# ifndef UNDERLINE
#  define UNDERLINE "\033[4m"
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 960
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 540
# endif

# ifndef SATURATION_MODIFIER
#  define SATURATION_MODIFIER 0.3
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
	t_data			img;
	double			julia_const[2];
	int				max_iteration;
	int				color_hue;
	int				mouse_pressed;
	double			zoom_factor;
}				t_vars;

void	plot_fractal(t_vars *vars);
void	print_help(t_vars *vars);

#endif
