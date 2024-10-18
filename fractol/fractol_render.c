#include "fractol.h"

static void	ft_choose_fractal(t_complex *z,
	t_complex *c, t_fractol *data_fractal)
{
	if (!ft_strncmp(data_fractal->name, "julia", 5))
	{
		c->real = data_fractal->julia_real;
		c->i = data_fractal->julia_i;
	}
	else if (!ft_strncmp(data_fractal->name, "mandelbrot", 10))
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static unsigned int	ft_get_color(double x, double y, t_fractol *data_fr)
{
	unsigned int	iterator;
	unsigned int	color;
	t_complex		c;
	t_complex		z;
	t_min_max		old_values;

	old_values.min = 0.0;
	old_values.max = (double)WIDTH;
	z.real = ft_scale_value(x, old_values, -2.0 / data_fr->zoom
			+ data_fr->move_x, 2.0 / data_fr->zoom + data_fr->move_x);
	old_values.max = (double)HEIGTH;
	z.i = ft_scale_value(y, old_values, -2.0 / data_fr->zoom
			+ data_fr->move_y, 2.0 / data_fr->zoom + data_fr->move_y);
	ft_choose_fractal(&z, &c, data_fr);
	iterator = 0;
	old_values.max = 10.0 * data_fr->zoom;
	while (iterator < (unsigned int)old_values.max)
	{
		z = ft_add_complex(ft_square_complex(z), c);
		if (z.real * z.real + z.i * z.i > 4)
			break ;
		iterator++;
	}
	color = (unsigned int)ft_scale_value(iterator, old_values, BLACK, WHITE);
	return (color);
}

static void	ft_put_pixel(int x, int y, t_fractol *data_fractal)
{
	int				pos;
	unsigned int	color;

	color = ft_get_color((double)x, (double)y, data_fractal);
	pos = y * data_fractal->img.line_length
		+ x * (data_fractal->img.bits_per_pixel / 8);
	*(unsigned int *)(data_fractal->img.pixel_ptr + pos) = color;
}

void	ft_fractal_render(t_fractol *data_fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(x, y, data_fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data_fractal->mlx_connection,
		data_fractal->mlx_window, data_fractal->img.img, 0, 0);
}
