#include <stdio.h>

# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF

# define HEIGTH	900
# define WIDTH	900

typedef struct s_min_max
{
	double	min;
	double	max;
}	t_min_max;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	zoom;
	double	move_x;
	double	move_y;
	double	julia_real;
	double	julia_i;
}	t_fractol;

double	ft_scale_value(double value, t_min_max old,
	double new_min, double new_max)
{
	return ((value - old.min) / (old.max - old.min) * (new_max - new_min)
		+ new_min);
}

t_complex	ft_add_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	res;

	res.real = z.real * z.real - z.i * z.i;
	res.i = 2 * z.real * z.i;
	return (res);
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
	c.real = z.real;
	c.i = z.i;
	iterator = 0;
	old_values.max = 10.0 * data_fr->zoom;
	while (iterator < (unsigned int)old_values.max)
	{
		z = ft_add_complex(ft_square_complex(z), c);
		if (z.real * z.real + z.i * z.i > 4)
			break ;
		iterator++;
	}
    if (x == 450 && y == 450)
    {
        printf("i: %i\n", iterator);
        printf("max: %u\n", (unsigned int)old_values.max);
    }
	color = (unsigned int)ft_scale_value(iterator, old_values, BLACK, WHITE);
	return (color);
}

int main(void)
{
    t_fractol data;
    int x = 0;
    int y = 0;

    data.zoom = 1.1 * 1.1;
    data.move_x = 0.0;
    data.move_y = 0.0;
    while (y < HEIGTH)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (x == 450 && y == 450)
                printf("%u\n", ft_get_color((double)x, (double)y, &data));
            x++;
        }
        y++;
    }
    printf("%u\n", WHITE);
}
