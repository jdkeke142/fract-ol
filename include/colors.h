/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:54:49 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/17 13:19:13 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <math.h>

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_palette {
	int		base_hue;
	double	saturation_modifier;
}				t_palette;

typedef struct s_palette_set {
	int			palettes_count;
	t_palette	palettes[16];
}				t_palette_set;

int				create_trgb(int t, int r, int g, int b);
t_rgb			hsv_to_rgb(double h, double s, double v);
t_palette_set	init_palettes(void);

#endif
