#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
typedef struct s_flags
{
	int pres;
	int zero;
	int left;
	int right;
	int left_handle;
	int right_handle;
	int pres_num;
}				t_flag;
typedef struct s_params
{
	int before_dot;
	int after_dot;

}				t_params;
int out_u_length(long i);
void hex(long quotient);
int hex_length(long quotient);
void hex_min(long quotient);
void out_u(long i);
t_flag flag_handler(t_flag flag,const char *p);
t_flag init_flag(t_flag flag);
int is_conv(char p);
void check_conv(const char *p,va_list argptr,int t);
int is_conv(char p);
t_flag check_star_left(t_flag flag,t_params *params);
int ft_printf(const char *p,...);
int handle_int(int t,t_flag flag,t_params params);
int print_char(char c, t_flag flag,t_params params);
int handle_s(char *out,t_params params ,t_flag flag);
int handle_per(t_flag flag,t_params params);
int handex_X(t_flag flag,t_params params,long num);
int x_zero(t_flag flag,t_params params,long num);
int x_handle(t_flag flag,t_params params,long num);
int u_handle(t_flag flag,t_params params,long num);
char *ft_ull_base(unsigned long long ull, int base);
int ft_printf(const char *p,...);
#endif