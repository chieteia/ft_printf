/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:50:49 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 05:17:46 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_no_flag(const char **fmt, int *res)
{
	const char *head;

	head = *fmt;
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, head, *fmt - head);
	*res += *fmt - head;
}

int		ft_print_with_flag(t_info *flag, va_list *ap, \
											const char *head, const char **fmt)
{
	if (flag->specifier == NO_SPECIFIER)
		return (write(1, head, *fmt - head));
	(*fmt)++;
	if (flag->specifier == E_CHAR)
		return (ft_print_c(flag, ap));
	if (flag->specifier == E_STRING)
		return (ft_print_s(flag, ap));
	if (flag->specifier == E_POINTER)
		return (ft_print_p(flag, ap, "0123456789abcdef"));
	if (flag->specifier == E_DECIMAL || flag->specifier == E_INTEGER)
		return (ft_print_di(flag, ap, "0123456789"));
	if (flag->specifier == E_UNSIGNED)
		return (ft_print_u_sx_lx(flag, ap, "0123456789"));
	if (flag->specifier == E_XDECIMAL_SMALL)
		return (ft_print_u_sx_lx(flag, ap, "0123456789abcdef"));
	if (flag->specifier == E_XDECIMAL_LARGE)
		return (ft_print_u_sx_lx(flag, ap, "0123456789ABCDEF"));
	if (flag->specifier == E_PERCENT)
		return (ft_print_percent(flag));
	return (-1);
}

void	ft_make_flags(t_info *flag, va_list *ap, const char **fmt, int *res)
{
	int			index;
	int			len;
	const char	*head;

	head = (*fmt)++;
	ft_init_flag(flag);
	while ((index = ft_strchr("-0", **fmt)) >= 0)
	{
		flag->flag[index] = 1;
		(*fmt)++;
	}
	if (flag->flag[E_MINUS])
		flag->flag[E_ZERO] = 0;
	flag->width = ft_str_to_num(flag, ap, fmt, 0);
	if (**fmt == '.')
	{
		(*fmt)++;
		flag->prec = ft_str_to_num(flag, ap, fmt, 1);
	}
	flag->specifier = ft_strchr("cspdiuxX%", **fmt);
	if (flag->width >= INT_MAX || flag->prec >= INT_MAX
		|| (len = ft_print_with_flag(flag, ap, head, fmt)) < 0)
		*res = -1;
	else
		*res += len;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_info		flag;
	int			res;

	res = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			ft_print_no_flag(&fmt, &res);
		else
			ft_make_flags(&flag, &ap, &fmt, &res);
		if (res == -1)
			return (-1);
	}
	va_end(ap);
	return (res);
}
