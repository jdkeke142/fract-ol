/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:54:49 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/20 21:46:58 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}				t_rgb;

int				create_trgb(int t, int r, int g, int b);
t_rgb			hsv_to_rgb(double h, double s, double v);

#endif
