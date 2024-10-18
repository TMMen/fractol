#include "fractol.h"

int	ft_strncmp(char *str1, char *str2, int n)
{
	if (NULL == str1 || NULL == str2 || n <= 0)
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && n > 0)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (NULL == str || fd < 0)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

double	ft_atod(char *str)
{
	long int	integer_part;
	double		fractional_part;
	double		pow;
	int			sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str == '-')
			sign = -sign;
	str++;
	while (*str && *str != '.')
		integer_part = integer_part * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str++ - '0') * pow;
	}
	return (((double)integer_part + fractional_part) * sign);
}
