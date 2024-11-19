/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:59:12 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/19 16:57:55 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOLE_H
# define FRACTOLE_H

# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define MAXITER 100
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

typedef struct s_coordone
{
	double	xmin;
	double	xmax;
	double	ymax;
	double	ymin;
	double	ci;
	double	cr;
} t_fractale;

typedef struct s_fractole
{
	void	*winp;
	void	*ptr;
	void	*imp;
	char	*addr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	int name;
	t_fractale fract;
} t_data;

void	julia(t_data *data, t_fractale *fract);
int		draw_julia( double cr, double ci, double z_im, double z_re);
int		set_color(int i);
void	put_pixel(t_data *data, int color , int x, int y);
void	zoomup(t_data* data, t_fractale *fract, int x, int y);
void	zoomdown(t_data* data, t_fractale *fract, int x, int y);
double	ft_atof(char *s, double decimal, double fraction);
void	ft_putstr(char *s);
int	ft_strcmp(char *s1, char *s2);
void	put_pixel(t_data *data, int color , int x, int y);
int	set_color(int i);
void	mandelbrot(t_data *data, t_fractale *fract);
int	draw_mandelbrot( double x, double y, double z_im, double z_re);
#endif
