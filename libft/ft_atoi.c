#include "libft.h"

int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_isdigit1 (char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	res = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] && (ft_isdigit1(str[i])))
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647 && neg == 1)
			return (-1);
		if (res > 2147483648 && neg == -1)
			return (0);
		i++;
	}
	return (res * neg);
}
