#include "fractol.h"

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
