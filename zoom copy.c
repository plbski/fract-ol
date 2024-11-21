/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:11:07 by plbuet            #+#    #+#             */
/*   Updated: 2024/11/21 11:52:12 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

void	zoomdown(t_data *data, t_fractale *fract, int x, int y)
{
	t_zoom	zoom;

	zoom.mx = fract->xmin + (x / (double)WIDTH) * (fract->xmax - fract->xmin);
	zoom.my = fract->ymin + (y / (double)HEIGTH) * (fract->ymax - fract->ymin);
	zoom.new_width = (fract->xmax - fract->xmin) * 0.7;
	zoom.new_height = (fract->ymax - fract->ymin) * 0.7;
	zoom.ratio_x = (zoom.mx - fract->xmin) / (fract->xmax - fract->xmin);
	zoom.ratio_y = (zoom.my - fract->ymin) / (fract->ymax - fract->ymin);
	fract->xmin = zoom.mx - (zoom.ratio_x * zoom.new_width);
	fract->xmax = zoom.mx + ((1 - zoom.ratio_x) * zoom.new_width);
	fract->ymin = zoom.my - (zoom.ratio_y * zoom.new_height);
	fract->ymax = zoom.my + ((1 - zoom.ratio_y) * zoom.new_height);
	if (data->name == 2)
		mandelbrot(data, fract);
	else if (data->name == 1)
		julia(data, fract);
	else
		burningship(data, fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
}

void	zoomup(t_data *data, t_fractale *fract, int x, int y)
{
	t_zoom	zoom;

	zoom.mx = fract->xmin + (x / (double)WIDTH) * (fract->xmax - fract->xmin);
	zoom.my = fract->ymin + (y / (double)HEIGTH) * (fract->ymax - fract->ymin);
	zoom.new_width = (fract->xmax - fract->xmin) * 1.3;
	zoom.new_height = (fract->ymax - fract->ymin) * 1.3;
	zoom.ratio_x = (zoom.mx - fract->xmin) / (fract->xmax - fract->xmin);
	zoom.ratio_y = (zoom.my - fract->ymin) / (fract->ymax - fract->ymin);
	fract->xmin = zoom.mx - (zoom.ratio_x * zoom.new_width);
	fract->xmax = zoom.mx + ((1 - zoom.ratio_x) * zoom.new_width);
	fract->ymin = zoom.my - (zoom.ratio_y * zoom.new_height);
	fract->ymax = zoom.my + ((1 - zoom.ratio_y) * zoom.new_height);
	if (data->name == 2)
		mandelbrot(data, fract);
	else if (data->name == 1)
		julia(data, fract);
	else
		burningship(data, fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
}

void	mouve(t_fractale *fract, int key)
{
	double	x;
	double	y;

	x = (fract->xmax - fract->xmin) * 0.1;
	y = (fract->ymax - fract->ymin) * 0.1;
	if (key == LEFT)
	{
		fract->xmin = fract->xmin - x;
		fract->xmax = fract->xmax - x;
	}
	else if (key == RIGHT)
	{
		fract->xmin = fract->xmin + x;
		fract->xmax = fract->xmax + x;
	}
	else if (key == UP)
	{
		fract->ymin = fract->ymin - y;
		fract->ymax = fract->ymax - y;
	}
	else if (key == DOWN)
	{
		fract->ymin = fract->ymin + y;
		fract->ymax = fract->ymax + y;
	}
}
