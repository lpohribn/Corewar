/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:26:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/28 17:26:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_PRINTF_BUFF_SIZE 4096
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include "libft.h"

# define PF_EOC "\e[0;00m"
# define PF_RED "\e[0;31m"
# define PF_GREEN "\e[0;32m"
# define PF_YELLOW "\e[0;33m"
# define PF_BLUE "\e[0;34m"
# define PF_PURPLE "\e[0;35m"
# define PF_CYAN "\e[0;36m"
# define PF_WHITE "\e[0;37m"

# define EOC_CODE 0x636F65
# define RED_CODE 0x646572
# define GREEN_CODE 0x6E65657267
# define YELLOW_CODE 0x776F6C6C6579
# define BLUE_CODE 0x65756C62
# define PURPLE_CODE 0x656C70727570
# define CYAN_CODE 0x6E617963
# define WHITE_CODE 0x6574696877

typedef	union	u_bytes
{
	unsigned int	byte3:24;
	unsigned int	byte4;
	uintmax_t		byte5:40;
	uintmax_t		byte6:48;
	uintmax_t		byte7:56;
	uintmax_t		byte8;
}				t_bytes;

typedef	struct	s_printf_flags
{
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	sharp:1;
	unsigned int	space:1;
	unsigned int	long_db:1;
	unsigned int	apostr:1;
	unsigned int	sign:1;
	unsigned int	flt:1;
	unsigned int	size:4;
}				t_printf_flags;

typedef	struct	s_data_printf
{
	char			buff[FT_PRINTF_BUFF_SIZE];
	int				buff_i;
	int				ret;
	char			chr;
	int				width;
	int				prec;
	t_printf_flags	fl;
	va_list			begin;
	va_list			param_arg;
	size_t			data_arg;
	int				fd;
	int				clr;
}				t_data_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vdprintf(const int fd, const char *restrict format,
				va_list *arg);
int				ft_dprintf(const int fd, const char *restrict format, ...);
int				ft_fprintf(const char *file, const char *restrict format, ...);

const char		*ft_spec(t_data_printf *d, const char *pos, va_list *arg);
const char		*ft_color(t_data_printf *d, const char *pos);

void			ft_conv(t_data_printf *d, char chr, va_list *arg);

void			ft_print_buff(t_data_printf *d);

void			ft_set_flags(t_data_printf *d);

int				ft_star(t_data_printf *d, const char **pos, va_list *arg);

va_list			*ft_count_arg(t_data_printf *d, int arg);

int				ft_count_dig(t_data_printf *d, uintmax_t value, int base);
int				ft_count_double(long double val);

void			ft_printf_itoa(t_data_printf *d, uintmax_t value,
				int base, int len);
void			ft_printf_apo_itoa(t_data_printf *d, uintmax_t value,
				int base, int len);

void			ft_put_width(t_data_printf *d, int val_len);
void			ft_put_prec(t_data_printf *d, uintmax_t val, int len, int base);
void			ft_put_sign(t_data_printf *d, uintmax_t val, int base);

void			ft_char(t_data_printf *d, wchar_t value);
void			ft_int(t_data_printf *d, va_list *arg, int base);
void			ft_string(t_data_printf *d, char *value);
void			ft_wstring(t_data_printf *d, wchar_t *value);
void			ft_write_chr(t_data_printf *d, va_list *arg);

void			ft_float(t_data_printf *d, long double val);
void			ft_expo_form(t_data_printf *d, long double val);
void			ft_g_float(t_data_printf *d, long double val);
void			ft_printf_dtoa(t_data_printf *d, long double val,
				long double base);
void			ft_a_float(t_data_printf *d, long double val);

void			ft_handle_nan(t_data_printf *d, long double val);

int				ft_calc_expo(t_data_printf *d, long double *val);

long double		ft_get_float_val(t_data_printf *d, va_list *arg);

void			ft_nonprint_str(t_data_printf *d, unsigned char *value);
void			ft_nonprint_char(t_data_printf *d, unsigned char value);
void			ft_print_date(t_data_printf *d);
void			ft_two_dimensional_array(t_data_printf *d, va_list *arg);

#endif
