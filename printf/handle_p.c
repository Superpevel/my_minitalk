/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:23:09 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:28:06 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_zero(t_flag flag, long num)
{
	int	words;

	words = 0;
	if (((flag.pres == 1 && flag.pres_num == 0)
			|| (flag.after_dot == 0 && flag.pres_num == 1)) && num == 0)
	{
		flag.spaces = flag.before_dot;
		while (flag.spaces--)
		{
			ft_putchar_fd(' ', 1);
			words++;
		}
		return (words);
	}
	return (-1);
}

int	words_out(unsigned long long num, int words, char *prefix, char *out)
{
	if (num != 0)
	{
		ft_putstr_fd(prefix, 1);
		ft_putstr_fd(out, 1);
	}
	else
	{
		ft_putstr_fd(prefix, 1);
		ft_putchar_fd('0', 1);
		words += 2;
	}
	return (words);
}

int	print_p(t_flag flag, int words, unsigned long long num, char *out)
{
	char	*prefix;

	prefix = "0x";
	if (flag.left == 1)
		words = ft_write(flag.zeros, words, 2);
	if (flag.left == 1)
		words = words_out(num, words, prefix, out);
	words = ft_write(flag.spaces, words, 1);
	if (flag.right == 1)
		words = ft_write(flag.zeros, words, 2);
	if (flag.right == 1)
		words = words_out(num, words, prefix, out);
	return (words);
}

int	return_p(unsigned long long num, char *out, t_flag flag)
{
	int	len ;
	int	words;

	words = 0;
	len = ft_strlen(out) + 2;
	if (num != 0)
		words += len;
	else
	{
		len = 3;
		words += 1;
	}
	flag_params(len, &flag);
	words = print_p(flag, words, num, out);
	return (words);
}

int	handle_p(t_flag flag, void *pointer)
{
	int					words;
	char				*out;
	unsigned long long	num;

	words = 0;
	num = -1;
	if (!pointer)
	{
		out = ft_strdup("");
		if (flag.pres == 0)
			num = 0;
	}
	else
	{
		num = (unsigned long long)pointer;
		out = to_lower_str(ft_ull_base(num, 16));
	}
	flag.zeros = p_zero(flag, num);
	if (flag.zeros >= 0)
		return (flag.zeros);
	else
		flag.zeros = 0;
	words = return_p(num, out, flag);
	free(out);
	return (words);
}
