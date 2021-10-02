/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:57:47 by selbert           #+#    #+#             */
/*   Updated: 2021/10/02 13:18:58 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Error signal!\n", 1);
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Error signal!\n", 1);
			exit(0);
		}
	}
	usleep(500);
}

int	send_message(int server_pid, char *msg)
{
	int		i;

	i = 0;
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, server_pid);
		i++;
	}
	return (0);
}

void	handler(int signum, siginfo_t *siginfo, void *unused)
{
	ft_putstr_fd("Signal received\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = handler;
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	if (argc == 3)
		send_message(atoi(argv[1]), argv[2]);
	else
		error("Error arguments\n");
	while (1)
		pause();
	return (0);
}
