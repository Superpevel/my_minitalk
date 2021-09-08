#include "../minitalk.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	error(char *str)
{
	ft_putstr_fd(str,1);
	exit(0);
}

void	sig_to_str(int bin)
{
	char	c;
	int		i;

	i = 0;
	c = '\0';
	c += (bin << i++);
	if (i > 7)
	{
		if (c == '\0')
			ft_putchar_fd('\n',1);
		else
			ft_putchar_fd(c,1);
		c = 0;
		i = 0;
	}
}

void handler(int signum,siginfo_t *siginfo,void *unused)
{
    static int ascii = 0;
    static int power = 0;
    (void)unused;
    if (signum == SIGUSR1)
    {
        ascii += 1 << (7-power);
    }
    power+=1;
    if(power == 8)
    {
        ft_putchar_fd(ascii,1);
        power=0;
        ascii=0;
        if(kill(siginfo->si_pid,SIGUSR2)==-1)
            error("ERROR SIGNAL\n");
    }

}
int main(int argc, char **argv)
{
    struct sigaction catch;
    
    ft_putstr_fd("The PID is: ",1);
	int pid =getpid();
    ft_printf("%d",pid);
    // ft_putnbr_fd(1,getpid());
    ft_printf("\n");
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		error("Error sigaction\n");
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	while (1)
		pause();
    return(0);
}