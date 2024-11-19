/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:11:07 by plbuet            #+#    #+#             */
/*   Updated: 2024/11/19 16:59:12 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

void zoomdown(t_data* data, t_fractale *fract, int x, int y)
{
	double mx;
	double my;
	double new_width;
	double new_height;
	double ratio_x;
	double ratio_y;
	
	mx = fract->xmin + (x / (double)WIDTH) * (fract->xmax - fract->xmin);
	my = fract->ymin + (y / (double)HEIGTH) * (fract->ymax - fract->ymin);
	new_width = (fract->xmax - fract->xmin) * 0.7;
	new_height = (fract->ymax - fract->ymin) * 0.7;
	ratio_x = (mx - fract->xmin) / (fract->xmax - fract->xmin);
	ratio_y = (my - fract->ymin) / (fract->ymax - fract->ymin);
	fract->xmin = mx - (ratio_x * new_width) ;
	fract->xmax = mx + ((1 - ratio_x) * new_width) ;
	fract->ymin = my - (ratio_y  * new_height);
	fract->ymax = my + ((1 - ratio_y) * new_height);
	if (data->name == 2)
		mandelbrot(data, fract);
	else
		julia(data, fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
}

void zoomup(t_data* data, t_fractale *fract, int x, int y)
{
	double mx;
	double my;
	double new_width;
	double new_height;
	double ratio_x;
	double ratio_y;
	
	mx = fract->xmin + (x / (double)WIDTH) * (fract->xmax - fract->xmin);
	my = fract->ymin + (y / (double)HEIGTH) * (fract->ymax - fract->ymin);
	new_width = (fract->xmax - fract->xmin) * 1.3;
	new_height = (fract->ymax - fract->ymin) * 1.3;
	ratio_x = (mx - fract->xmin) / (fract->xmax - fract->xmin);
	ratio_y = (my - fract->ymin) / (fract->ymax - fract->ymin);
	fract->xmin = mx - (ratio_x * new_width) ;
	fract->xmax = mx + ((1 - ratio_x) * new_width) ;
	fract->ymin = my - (ratio_y  * new_height);
	fract->ymax = my + ((1 - ratio_y) * new_height);
	if (data->name == 2)
		mandelbrot(data, fract);
	else
		julia(data, fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
}

