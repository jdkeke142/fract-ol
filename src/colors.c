/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:30:45 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 15:10:45 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_rgb	hsv_to_rgb(double h, double s, double v)
{
	long	i;
	double	f;
	double	p;
	double	q;
	double	t;

	if (h >= 360)
		h = 0;
	h /= 60;
	i = h;
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - (s * f));
	t = v * (1 - (s * (1 - f)));
	if (i == 0)
		return ((t_rgb){v * 255, t * 255, p * 255});
	else if (i == 1)
		return ((t_rgb){q * 255, v * 255, p * 255});
	else if (i == 2)
		return ((t_rgb){p * 255, v * 255, t * 255});
	else if (i == 3)
		return ((t_rgb){p * 255, q * 255, v * 255});
	else if (i == 4)
		return ((t_rgb){t * 255, p * 255, v * 255});
	return ((t_rgb){v * 255, p * 255, q * 255});
}

t_palette_set	init_palettes(void)
{
	return ((t_palette_set){6, {(t_palette){60, 0.3}, (t_palette){120, 0.3},
	(t_palette){180, 0.3}, (t_palette){240, 0.3}, (t_palette){300, 0.3},
	(t_palette){360, 0.3}}});
}
