/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:40:42 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/25 10:42:27 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_burningship( double x, double y, double z_im, double z_re)
{
	int		i ;
	double	tmp;

	i = 0;
	while (i < MAXITER && (z_im * z_im + z_re * z_re <= 4))
	{
		tmp = z_re * z_re - z_im * z_im + x;
		z_im = fabs(2 * z_im * z_re) + y;
		z_re = tmp;
		i ++;
	}
	return (i);
}

void	burningship(t_data *data, t_fractale *fract)
{
	double	x ;
	double	y;
	double	z_re;
	double	z_im ;
	int		color;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = fract->xmin + (fract->xmax - fract->xmin) * x / WIDTH;
			z_im = fract->ymin + (fract->ymax - fract->ymin) * y / HEIGTH;
			color = draw_burningship(z_re, z_im, z_im, z_re);
			color = set_color(color, data);
			put_pixel(data, color, x, y);
			x ++;
		}
		y ++;
	}
}
