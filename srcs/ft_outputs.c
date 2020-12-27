/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:08:13 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 05:03:55 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_digits(t_info *flag)
{
	int				digits;
	long long		ll_num;

	digits = 0;
	if (flag->specifier == E_DECIMAL || flag->specifier == E_INTEGER)
	{
		ll_num = (long long)flag->num_int;
		ll_num = (ll_num < 0) ? -ll_num : ll_num;
	}
	else if (flag->specifier == E_POINTER)
		ll_num = flag->num_pointer;
	else
		ll_num = (long long)flag->num_uint;
	if (ll_num == 0)
		return (1);
	while (ll_num > 0)
	{
		ll_num /= flag->num_base;
		digits++;
	}
	if (flag->num_int < 0)
		digits++;
	return (digits);
}

int		ft_put_space(t_info *flag, int padding)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (flag->flag[E_ZERO] && flag->width > flag->num_digits && flag->prec < 0)
		return (0);
	if (flag->prec == 0 && flag->num_int == 0 && flag->num_uint == 0)
		while (i++ < flag->width - padding)
			len += ft_put_char(' ');
	else if (flag->num_digits > flag->prec)
		while (i++ < flag->width - flag->num_digits - padding)
			len += ft_put_char(' ');
	else if (flag->num_int < 0)
		while (i++ < flag->width - flag->prec - padding - 1)
			len += ft_put_char(' ');
	else
		while (i++ < flag->width - flag->prec - padding)
			len += ft_put_char(' ');
	return (len);
}

int		ft_putnbr_p_u_sx_lx(uintptr_t num, int base, char *str)
{
	int res;

	res = 0;
	if (num / base == 0)
	{
		res += ft_put_char(str[num]);
		return (res);
	}
	res += ft_putnbr_p_u_sx_lx(num / base, base, str);
	res += ft_put_char(str[num % base]);
	return (res);
}
