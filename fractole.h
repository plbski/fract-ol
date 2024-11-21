/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:59:12 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/21 16:52:29 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLE_H
# define FRACTOLE_H

# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define MAXITER 90
# define HEIGTH 1000
# define WIDTH 1000
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define CL 1
# define CR 2
# define ZOOM 0.9
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define CRP 12
# define CRM 0
# define CIP 13
# define CIM 1

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}t_rgb;

typedef struct s_coordone
{
	double	xmin;
	double	xmax;
	double	ymax;
	double	ymin;
	double	ci;
	double	cr;
	double	color;
}t_fractale;

typedef struct s_fractole
{
	void		*winp;
	void		*ptr;
	void		*imp;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			name;
	t_fractale	fract;
	t_rgb		rgb;
}t_data;

typedef struct s_zoom
{
	double	mx;
	double	my;
	double	new_width;
	double	new_height;
	double	ratio_x;
	double	ratio_y;
}t_zoom;


void	julia(t_data *data, t_fractale *fract);
int		draw_julia( double cr, double ci, double z_im, double z_re);
int		set_color(int i, t_data *data);
void	put_pixel(t_data *data, int color, int x, int y);
void	zoomup(t_data *data, t_fractale *fract, int x, int y);
void	zoomdown(t_data *data, t_fractale *fract, int x, int y);
double	ft_atof(char *s, double decimal, double fraction);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
void	put_pixel(t_data *data, int color, int x, int y);
void	mandelbrot(t_data *data, t_fractale *fract);
int		draw_mandelbrot( double x, double y, double z_im, double z_re);
int		handle_key(int key_press, t_data *data);
int		handle_mouse(int mouse_put, int x, int y, t_data *data);
void	mouve(t_fractale *fract, int key);
void	burningship(t_data *data, t_fractale *fract);

#endif
