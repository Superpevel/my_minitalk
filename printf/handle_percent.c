/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:23:14 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:23:15 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_per(t_flag flag)
{
	int	words;

	words = 1;
	if (flag.zero == 0)
		flag.spaces = flag.before_dot - 1;
	else
		flag.zeros = flag.before_dot - 1;
	if (flag.left == 1)
		ft_putchar_fd('%', 1);
	while (flag.spaces-- > 0)
	{
		ft_putchar_fd(' ', 1);
		words++;
	}
	while (flag.zeros-- > 0)
	{
		ft_putchar_fd('0', 1);
		words++;
	}
	if (flag.right == 1)
		ft_putchar_fd('%', 1);
	return (words);
}
