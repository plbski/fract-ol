/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:18:32 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/21 17:40:54 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

int	close_prog(void *param)
{
	mlx_destroy_window(((t_data *)param)->ptr, ((t_data *)param)->winp);
	exit(0);
	return (0);
}

void	check_input(int c, char **s)
{
	if (c < 2)
	{
		ft_putstr("\033[0;31mERROR preciser la farctale voulue");
		ft_putstr("\033[0;36m\nnom:\nsi julia\nconst im:\nconst reel");
		exit(1);
	}
	if (ft_strcmp(s[1], "julia") != 0 && ft_strcmp(s[1], "mandelbrot") != 0
		&& ft_strcmp(s[1], "burningship") != 0)
	{
		ft_putstr("\033[0;31mERRORfractale non reconnu");
		ft_putstr("\033[0;36m\n nom : \n si julia \n const im: \n const reel");
		exit(1);
	}
	if (ft_strcmp(s[1], "julia") == 0 && c < 4)
	{
		ft_putstr("\033[0;31mERROR nb d'argument invalide");
		ft_putstr("\033[0;36m\nnom :\nsi julia\nconst im:\nconst reel");
		exit(1);
	}
}

void	ini_img(t_data *img, char **v)
{
	if (ft_strcmp(v[1], "julia") == 0)
	{
		img->fract.ci = ft_atof(v[2], 0, 0);
		img->fract.cr = ft_atof(v[3], 0, 0);
		img->name = 1;
	}
	else if (ft_strcmp(v[1], "mandelbrot") == 0)
		img->name = 2;
	else
		img->name = 3;
	img->fract.xmax = 2;
	img->fract.xmin = -2;
	img->fract.ymax = 2;
	img->fract.ymin = -2;
	img->ptr = mlx_init();
	img->winp = mlx_new_window(img->ptr, WIDTH, HEIGTH, "fractale");
	img->imp = mlx_new_image(img->ptr, WIDTH, HEIGTH);
	img->addr = mlx_get_data_addr(img->imp, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	img->rgb.r = 255;
	img->rgb.g = 17;
	img->rgb.b = 17;
}

int	main(int c, char **v)
{
	t_data	img;

	check_input(c, v);
	ini_img(&img, v);
	if (img.name == 1)
		julia(&img, &img.fract);
	else if (img.name == 2)
		mandelbrot(&img, &img.fract);
	else
		burningship(&img, &img.fract);
	mlx_put_image_to_window(img.ptr, img.winp, img.imp, 0, 0);
	mlx_mouse_hook(img.winp, handle_mouse, &img);
	mlx_key_hook(img.winp, handle_key, &img);
	mlx_hook(img.winp, 17, 0, close_prog, &img);
	mlx_loop(img.ptr);
	return (0);
}
