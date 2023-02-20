/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:59:58 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 19:07:55 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "ft_string.h"
#include "ft_stdio.h"

void	init(t_fractal_type fractal_type)
{
	t_vars			vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
			"Fract'ol");
	vars.mouse_pressed = 0;
	vars.julia_const[0] = 0.285;
	vars.julia_const[1] = 0.01;
	vars.max_iteration = 50;
	vars.img.img = mlx_new_image(vars.mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.fractal = get_fractal(fractal_type);
	vars.complex_pos = vars.fractal.complex_pos;
	vars.color_hue = HUE_FACTOR;
	vars.zoom_factor = 1;
	mlx_hook(vars.win, 4, 1L << 2, handle_mouse_hooks, &vars);
	mlx_hook(vars.win, 5, 1L << 3, julia_const_disable, &vars);
	mlx_hook(vars.win, 6, 1L << 6, julia_const, &vars);
	mlx_hook(vars.win, 17, 1L << 17, destroy, &vars);
	mlx_key_hook(vars.win, handle_key_hooks, &vars);
	plot_fractal(&vars);
	print_help(&vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char *argv[])
{
	t_fractal_type	fractal_type;
	char			*name_arg;

	if (argc >= 2)
	{
		name_arg = argv[1];
		if (!ft_strncmp(name_arg, "mandelbrot", ft_strlen(name_arg)))
			fractal_type = FR_MANDELBROT;
		else if (!ft_strncmp(name_arg, "julia", ft_strlen(name_arg)))
			fractal_type = FR_JULIA;
		else if (!ft_strncmp(name_arg, "tricorn", ft_strlen(name_arg)))
			fractal_type = FR_TRICORN;
		else if (!ft_strncmp(name_arg, "burningship", ft_strlen(name_arg)))
			fractal_type = FR_BURNINGSHIP;
		else
		{
			ft_printf("Invalid fractal type ! Valid fractals are"
				": mandelbrot/julia/tricorn/burningship\n");
			return (0);
		}
		init(fractal_type);
	}
	ft_printf("Invalid args provided ! Please use : ./fract_ol <mandelbrot"
		"/julia/tricorn/burningship>\n");
	return (0);
}
