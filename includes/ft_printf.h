/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:38:52 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 05:04:43 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# define DEFAULT -1
# define NO_SPECIFIER -1

typedef	enum	e_specifier
{
	E_CHAR,
	E_STRING,
	E_POINTER,
	E_DECIMAL,
	E_INTEGER,
	E_UNSIGNED,
	E_XDECIMAL_SMALL,
	E_XDECIMAL_LARGE,
	E_PERCENT,
}				t_specifier;

typedef	enum	e_flag
{
	E_MINUS,
	E_ZERO,
}				t_flag;

typedef struct	s_info
{
	int					flag[2];
	long long			width;
	long long			prec;
	int					specifier;
	int					num_int;
	unsigned int		num_uint;
	uintptr_t			num_pointer;
	int					num_digits;
	int					num_base;
}				t_info;

int				ft_isdigit(int c);
int				ft_put_char(int c);
int				ft_strchr(const char *s, int c);
int				ft_strlen(char *s);
void			ft_init_flag(t_info *flag);
int				ft_get_digits(t_info *flag);
int				ft_put_space(t_info *flag, int padding);
int				ft_putnbr_p_u_sx_lx(uintptr_t num, int base, char *str);
int				ft_print_c(t_info *flag, va_list *ap);
int				ft_print_s(t_info *flag, va_list *ap);
int				ft_putnbr_di(long long num, int base, char *str);
int				ft_setting_prec_di(t_info *flag, char *str);
int				ft_print_di(t_info *flag, va_list *ap, char *str);
int				ft_print_p(t_info *flag, va_list *ap, char *str);
int				ft_print_percent(t_info *flag);
int				ft_setting_prec_p_u_sx_lx(t_info *flag, char *str);
int				ft_print_u_sx_lx(t_info *flag, va_list *ap, char *str);
void			ft_print_no_flag(const char **fmt, int *res);
int				ft_print_with_flag(t_info *flag, va_list *ap, \
											const char *head, const char **fmt);
void			ft_make_flags(t_info *flag, va_list *ap, \
													const char **fmt, int *res);
int				ft_printf(const char *fmt, ...);
long long		ft_str_to_num(t_info *flag, va_list *ap, \
												const char **fmt, int dot_flag);

#endif
