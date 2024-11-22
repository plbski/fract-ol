/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:16:38 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/21 17:40:01 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

void	manage_const(int key_press, t_fractale *fract)
{
	if (key_press == CRP)
		fract->cr += 0.1;
	else if (key_press == CRM)
		fract->cr -= 0.1;
	else if (key_press == CIP)
		fract->ci += 0.1;
	else if (key_press == CIM)
		fract->ci -= 0.1;
}

void	color_change(t_rgb *rgb, int key)
{
	if (key == ONE)
	{
		rgb->r = 11;
		rgb->g = 31;
		rgb->b = 51;
	}
	else if (key == TWO)
	{
		rgb->r = 111;
		rgb->g = 111;
		rgb->b = 111;
	}
	else if (key == THREE)
	{
		rgb->r = 255;
		rgb->g = 17;
		rgb->b = 17;
	}
	else if (key == FOUR)
	{
		rgb->r = 0;
		rgb->g = 5;
		rgb->b = 0;
	}
}

int	handle_key(int key_press, t_data *data)
{
	if (key_press == ESC)
	{
		mlx_destroy_image(data->ptr, data->imp);
		mlx_destroy_window(data->ptr, data->winp);
		exit(0);
	}
	else if (key_press >= 123 && key_press <= 126)
		mouve(&data->fract, key_press);
	else if (key_press >= 18 && key_press <= 21)
		color_change(&data->rgb, key_press);
	else if (key_press == CRP || key_press == CRM
		|| key_press == CIP || key_press == CIM)
		manage_const(key_press, &data->fract);
	if (data->name == 2)
		mandelbrot(data, &data->fract);
	else if (data->name == 1)
		julia(data, &data->fract);
	else
		burningship(data, &data->fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
	return (0);
}

int	handle_mouse(int mouse_put, int x, int y, t_data *data)
{
	if (mouse_put == SCROLL_UP)
		zoomdown(data, &data->fract, x, y);
	else if (mouse_put == SCROLL_DOWN)
		zoomup(data, &data->fract, x, y);
	return (0);
}
