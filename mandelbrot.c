/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:37:46 by plbuet            #+#    #+#             */
/*   Updated: 2024/11/19 16:58:11 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

int draw_mandelbrot( double x, double y, double z_im, double z_re)
{
	int i ;
	double tmp;

	i = 0;
	while (i < MAXITER && (z_im * z_im + z_re * z_re <= 4))
	{
		tmp = z_re * z_re - z_im *  z_im + x;
		z_im = 2 * z_im * z_re + y;
		z_re = tmp;
		i ++;
	}
	return (set_color(i));
}

void	mandelbrot(t_data *data, t_fractale *fract)
{
	double	x ;
	double	y;
	double	z_re;
	double	z_im ;
	int	color;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = fract->xmin + (fract->xmax - fract->xmin) * x / WIDTH;
			z_im = fract->ymin + (fract->ymax - fract->ymin) * y/ HEIGTH;
			color = draw_mandelbrot(z_re, z_im, z_im, z_re);
			put_pixel(data, color, x, y);
			x ++;
		}
		y ++;
	}
}