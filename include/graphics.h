/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:25:38 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 22:21:10 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "fract_ol.h"

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 960
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 540
# endif

void	plot_fractal(t_vars *vars);
void	print_help(t_vars *vars);

#endif
