/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_sx_lx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:09:35 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 04:42:07 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_setting_prec_p_u_sx_lx(t_info *flag, char *str)
{
	int			res;
	int			num_len;
	uintptr_t	ull_num;

	res = 0;
	num_len = flag->num_digits;
	ull_num = (flag->specifier == E_POINTER) ?
	flag->num_pointer : flag->num_uint;
	if (flag->flag[E_ZERO] && flag->prec < 0)
	{
		num_len += (flag->specifier == E_POINTER) ? 2 : 0;
		while (flag->width > num_len++)
			res += ft_put_char('0');
	}
	else
		while (flag->prec > num_len++)
			res += ft_put_char('0');
	res += ft_putnbr_p_u_sx_lx(ull_num, flag->num_base, str);
	return (res);
}

int		ft_print_u_sx_lx(t_info *flag, va_list *ap, char *str)
{
	int len;

	len = 0;
	flag->num_uint = va_arg(*ap, unsigned int);
	flag->num_base = ft_strlen(str);
	flag->num_digits = ft_get_digits(flag);
	if (flag->prec == 0 && flag->num_uint == 0)
		len += ft_put_space(flag, 0);
	else if (flag->width <= flag->num_digits)
		len += ft_setting_prec_p_u_sx_lx(flag, str);
	else if (flag->flag[E_MINUS])
	{
		len += ft_setting_prec_p_u_sx_lx(flag, str);
		len += ft_put_space(flag, 0);
	}
	else
	{
		len += ft_put_space(flag, 0);
		len += ft_setting_prec_p_u_sx_lx(flag, str);
	}
	return (len);
}
