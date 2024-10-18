#include "fractol.h"

void	ft_initialize_hooks(t_fractol *data_fractal)
{
	mlx_hook(data_fractal->mlx_window, KeyPress,
		KeyPressMask, ft_handle_input_key, data_fractal);
	mlx_hook(data_fractal->mlx_window, ButtonPress,
		ButtonPressMask, ft_handle_input_mouse, data_fractal);
	mlx_hook(data_fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, ft_handle_input_close, data_fractal);
}

void	ft_initialize_data(t_fractol *data_fractal)
{
	data_fractal->zoom = 1.0;
	data_fractal->move_x = 0.0;
	data_fractal->move_y = 0.0;
}

void	ft_error_message_malloc(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	ft_fractal_initialize(t_fractol *data_fractal)
{
	data_fractal->mlx_connection = mlx_init();
	if (data_fractal->mlx_connection == NULL)
		ft_error_message_malloc(void);
	data_fractal->mlx_window = mlx_new_window(data_fractal->mlx_connection,
			WIDTH, HEIGTH, data_fractal->name);
	if (data_fractal->mlx_window == NULL)
	{
		mlx_destroy_display(data_fractal->mlx_connection);
		free(data_fractal->mlx_connection);
		ft_error_message_malloc(void);
	}
	data_fractal->img.img_ptr = mlx_new_image(data_fractal->mlx_connection,
		WIDTH, HEIGTH);
	if (data_fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(data_fractal->mlx_connection,
			data_fractal->mlx_window);
		mlx_destroy_display(data_fractal->mlx_connection);
		free(data_fractal->mlx_connection);
		ft_error_message_malloc(void);
	}
	ft_fractal_initialize_extension(data_fractal)
}

void	ft_fractal_initialize_extension(t_fractol *data_fractal)
{
	data_fractal->img.pixel_ptr = mlx_get_data_addr(data_fractal->img.img_ptr,
			&data_fractal->img.bits_per_pixel, &data_fractal->img.line_length,
			&data_fractal->img.endian);
	if (data_fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(data_fractal->mlx_connection,
			data_fractal->mlx_window);
		mlx_destroy_display(data_fractal->mlx_connection);
		free(data_fractal->mlx_connection);
		ft_error_message_malloc(void);
	}
	ft_initialize_data(data_fractal);
	ft_initialize_hooks(data_fractal);
}
