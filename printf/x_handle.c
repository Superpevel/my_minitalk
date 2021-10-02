/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:23:43 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:23:45 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_what(t_flag *flag, int len)
{
	if (flag->zero == 0)
	{
		flag->zeros = flag->after_dot - len;
		if (flag->zeros > 0)
			flag->spaces = flag->before_dot - flag->zeros - len;
		else
			flag->spaces = flag->before_dot - len;
	}
	if (flag->zero == 1)
	{
		flag->spaces = 0;
		flag->zeros = flag->before_dot - len;
		if (flag->after_dot == 0 && flag->pres_num == 1)
		{
			flag->spaces = flag->zeros;
			flag->zeros = 0;
		}
	}
}

int	print_x(t_flag flag, int words, char *hexa, unsigned int num)
{
	if (flag.left == 1)
		words = ft_write(flag.zeros, words, 2);
	if (flag.left == 1)
	{
		if (num != 0)
			ft_putstr_fd(hexa, 1);
		else
			ft_putchar_fd('0', 1);
	}
	words = ft_write(flag.spaces, words, 1);
	if (flag.right == 1)
		words = ft_write(flag.zeros, words, 2);
	if (flag.right == 1)
	{
		if (num != 0)
			ft_putstr_fd(hexa, 1);
		else
			ft_putchar_fd('0', 1);
	}
	return (words);
}

char	*to_lower_str(char *hexa)
{
	int	i;

	i = 0;
	while (hexa[i] != '\0')
	{
		hexa[i] = ft_tolower(hexa[i]);
		i++;
	}
	return (hexa);
}

int	x_handle(t_flag flag, unsigned int num)
{
	int		words;
	int		len;
	char	*hexa;

	words = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	flag.zeros = x_zero(flag, num);
	if (flag.zeros >= 0)
		return (flag.zeros);
	hexa = ft_ull_base((unsigned long long) num, 16);
	hexa = to_lower_str(hexa);
	len = ft_strlen(hexa);
	if (num != 0)
		words += len;
	else
	{
		len = 1;
		words += 1;
	}
	check_what(&flag, len);
	words = print_x(flag, words, hexa, num);
	free(hexa);
	return (words);
}
