/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:38:33 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/21 17:38:21 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

int	set_color(int i, t_data *data)
{
	int	r;
	int	g;
	int	b;

	if (i == MAXITER)
		return (0x000000);
	else if (i != 0)
	{
		r = (i * data->rgb.r) % 256;
		g = (i * data->rgb.g) % 256;
		b = (i * data->rgb.b) % 256;
		return ((r << 16) + (g << 8) + b);
	}
	else
		return ((data->rgb.r << 16) + (data->rgb.g << 8) + data->rgb.b);
}

void	put_pixel(t_data *data, int color, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_julia( double cr, double ci, double z_im, double z_re)
{
	int		i ;
	double	tmp;

	i = 0;
	while (i < MAXITER && (z_im * z_im + z_re * z_re <= 4))
	{
		tmp = z_re * z_re - z_im * z_im + cr;
		z_im = 2 * z_im * z_re + ci;
		z_re = tmp;
		i ++;
	}
	return (i);
}

void	julia(t_data *data, t_fractale *fract)
{
	int		x ;
	int		y ;
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
			color = draw_julia(fract->cr, fract->ci, z_im, z_re);
			color = set_color(color, data);
			put_pixel(data, color, x, y);
			x ++;
		}
		y ++;
	}
}
