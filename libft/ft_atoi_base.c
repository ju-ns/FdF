#include "libft.h"

static int	char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(char *str, int base)
{
	int	result;
	int	sign;
	int	value;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	value = char_to_value(*str);
	while (value >= 0 && value < base)
	{
		result = result * base + value;
		value = char_to_value(*++str);
	}
	return (result * sign);
}

