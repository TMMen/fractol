#include "fractol.h"

int	ft_handle_input_close(t_fractol *data_fractal)
{
	mlx_destroy_image(data_fractal->mlx_connection, data_fractal->img.img_ptr);
	mlx_destroy_window(data_fractal->mlx_connection, data_fractal->mlx_window);
	mlx_destroy_display(data_fractal->mlx_connection);
	free(data_fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	ft_handle_input_mouse(int input, t_fractol *data_fractal)
{
	if (input == SCROLL_UP)
		data_fractal->zoom *= 1.25;
	else if (input == SCROLL_DOWN)
		data_fractal->zoom *= 0.8;
	ft_fractal_render(data_fractal);
	return (0);
}

int	ft_handle_input_key(int input, t_fractol *data_fractal)
{
	if (input == KEY_PLUS)
		data_fractal->zoom *= 1.25;
	else if (input == KEY_MINUS)
		data_fractal->zoom *= 0.8;
	else if (input == KEY_RIGHT)
		data_fractal->move_x += 0.25 / data_fractal->zoom;
	else if (input == KEY_LEFT)
		data_fractal->move_x -= 0.25 / data_fractal->zoom;
	else if (input == KEY_UP)
		data_fractal->move_y -= 0.25 / data_fractal->zoom;
	else if (input == KEY_DOWN)
		data_fractal->move_y += 0.25 / data_fractal->zoom;
	else if (input == KEY_ESCAPE)
		ft_handle_close_input(data_fractal);
	ft_fractal_render(data_fractal);
	return (0);
}
