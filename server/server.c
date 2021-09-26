/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:56:01 by selbert           #+#    #+#             */
/*   Updated: 2021/09/26 17:56:03 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii;
	static int	power;

	(void)unused;
	if (signum == SIGUSR1)
	{
		ascii += 1 << (7 - power);
	}
	power += 1;
	if (power == 8)
	{
		ft_putchar_fd(ascii, 1);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			error("ERROR SIGNAL\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	ft_putstr_fd("The PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		error("Error sigaction\n");
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
