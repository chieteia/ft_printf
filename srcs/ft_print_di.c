/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:21:39 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/24 05:43:27 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putnbr_di(long long num, int base, char *str)
{
	int res;

	res = 0;
	if (num / base == 0)
	{
		res += ft_put_char(str[num]);
		return (res);
	}
	res += ft_putnbr_di(num / base, base, str);
	res += ft_put_char(str[num % base]);
	return (res);
}

int		ft_setting_prec_di(t_info *flag, char *str)
{
	int			i;
	int			len;
	int			num_abs_len;
	long long	ll_num_abs;

	i = 0;
	len = 0;
	if (flag->num_int < 0)
		len += ft_put_char('-');
	num_abs_len = (flag->num_int < 0) ? flag->num_digits - 1 : flag->num_digits;
	if (flag->prec > num_abs_len)
		while (i++ < flag->prec - num_abs_len)
			len += ft_put_char('0');
	else if (flag->flag[E_ZERO] && flag->prec < 0)
		while (i++ < flag->width - flag->num_digits)
			len += ft_put_char('0');
	ll_num_abs = (flag->num_int < 0) ?
	(long long)flag->num_int * -1 : (long long)flag->num_int;
	len += ft_putnbr_di(ll_num_abs, flag->num_base, str);
	return (len);
}

int		ft_print_di(t_info *flag, va_list *ap, char *str)
{
	int len;

	len = 0;
	flag->num_int = va_arg(*ap, int);
	flag->num_base = ft_strlen(str);
	flag->num_digits = ft_get_digits(flag);
	if (flag->prec == 0 && flag->num_int == 0)
		len += ft_put_space(flag, 0);
	else if (flag->width <= flag->num_digits)
		len += ft_setting_prec_di(flag, str);
	else if (flag->flag[E_MINUS])
	{
		len += ft_setting_prec_di(flag, str);
		len += ft_put_space(flag, 0);
	}
	else
	{
		len += ft_put_space(flag, 0);
		len += ft_setting_prec_di(flag, str);
	}
	return (len);
}
