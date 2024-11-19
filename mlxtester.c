
#include "fractole.h"

int close_prog(void *param)
{
	mlx_destroy_window(((t_data *)param)->ptr, ((t_data *)param)->winp);
	exit(0);
	return (0);
}
int handle_key(int key_press, t_data *data)
{
	if (key_press == ESC)
	{
		mlx_destroy_image(data->ptr, data->imp);
		mlx_destroy_window(data->ptr, data->winp);
		exit(0);
	}
	return (0);
}

int handle_mouse(int mouse_put, int x, int y, t_data *data) {
	if (mouse_put == SCROLL_UP)
		zoomdown(data, &data->fract, x, y);
	else if (mouse_put == SCROLL_DOWN)
		zoomup(data, &data->fract, x, y);
	return (0);
}

void check_input(int c, char **s)
{
	if (c < 2)
	{
		ft_putstr("ERROR preciser la farctale voulue \n nom : \n si julia \n const im: \n const reel");
		exit(0);
	}
	if (ft_strcmp(s[1], "julia") != 0 && ft_strcmp(s[1], "mandelbrot") != 0 )
	{
		ft_putstr("ERROR fractale non reconnu \n nom : \n si julia \n const im: \n const reel");
		exit(0);
	}
	if (ft_strcmp(s[1], "julia") == 0 && c < 4)
	{
		ft_putstr("ERROR nb d'argument invalide \n nom : \n si julia \n const im: \n const reel");
		exit(0);
	}

}
int main(int c, char **v)
{
	t_data img;

	check_input(c, v);
	if (ft_strcmp(v[1], "julia") == 0)
	{
		img.fract.ci = ft_atof(v[2], 0, 0);
		img.fract.cr = ft_atof(v[3], 0, 0);
		img.name = 1;
	}
	else
		img.name = 2;
	img.fract.xmax = 2;
	img.fract.xmin = -2;
	img.fract.ymax = 2;
	img.fract.ymin = -2;

	img.ptr = mlx_init();
	img.winp = mlx_new_window(img.ptr, WIDTH, HEIGTH, "fractale");
	img.imp = mlx_new_image(img.ptr, WIDTH, HEIGTH);
	img.addr = mlx_get_data_addr(img.imp, &img.bits_per_pixel, &img.size_line, &img.endian);
	mandelbrot(&img, &img.fract);
	mlx_put_image_to_window(img.ptr, img.winp, img.imp, 0, 0);

	mlx_mouse_hook(img.winp, handle_mouse, &img);
	mlx_key_hook(img.winp, handle_key, &img);
	mlx_hook(img.winp, 17, 0, close_prog, &img);
	mlx_loop(img.ptr);

	return (0);
}

