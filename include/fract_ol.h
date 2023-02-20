/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:04:59 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 23:20:35 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# ifndef RESET
#  define RESET "\x1B[0m"
# endif

# ifndef BOLD
#  define BOLD "\x1B[1m"
# endif

# ifndef UNDERLINE
#  define UNDERLINE "\033[4m"
# endif

typedef enum e_fractal_type
{
	FR_MANDELBROT,
	FR_JULIA,
	FR_TRICORN,
	FR_BURNINGSHIP
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
	double			julia_re;
	double			julia_im;
	int				angle;
	int				max_iteration;
	int				color_hue;
	int				mouse_pressed;
	double			zoom_factor;
}				t_vars;

void	print_help(t_vars *vars);

#endif
