
#include "fractole.h"

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
void zoom(t_data* data, t_fractale *fract, int x, int y) {
	double rx = fract->xmax - fract->xmin;
    double ry = fract->ymax - fract->ymin;
    double cx = fract->xmin + (x / (double)WIDTH) * rx;
    double cy = fract->ymin + (y / (double)HEIGTH) * ry;
    fract->xmin = cx - (rx / 1.1) / 5;
    fract->xmax = cx + (rx / 1.1) / 5;
    fract->ymin = cy - (ry / 1.1) / 5;
    fract->ymax = cy + (ry / 1.1) / 5;
    julia(data, fract);
	mlx_put_image_to_window(data->ptr, data->winp, data->imp, 0, 0);
}

int handle_mouse(int mouse_put, int x, int y, t_data *data) {
    if (mouse_put == SCROLL_UP)
        zoom(data, &data->fract, x, y);
    return (0);
}

int main()
{
	t_data img;
	img.fract.ci = 0.01;
	img.fract.cr = 0.285;
	img.fract.xmax = 2;
	img.fract.xmin = -2;
	img.fract.ymax = 2;
	img.fract.ymin = -2;

	img.ptr = mlx_init();
	img.winp = mlx_new_window(img.ptr, WIDTH, HEIGTH, "julia");
	img.imp = mlx_new_image(img.ptr, WIDTH, HEIGTH);
	img.addr = mlx_get_data_addr(img.imp, &img.bits_per_pixel, &img.size_line, &img.endian);
	julia(&img, &img.fract);
	mlx_put_image_to_window(img.ptr, img.winp, img.imp, 0, 0);

	mlx_mouse_hook(img.winp, handle_mouse, &img);
	mlx_key_hook(img.winp, handle_key, &img);
	mlx_loop(img.ptr);

	return (0);
}

