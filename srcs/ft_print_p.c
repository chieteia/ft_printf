/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:34:57 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 04:41:44 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_p(t_info *flag, va_list *ap, char *str)
{
	int len;

	len = 0;
	flag->num_pointer = (uintptr_t)va_arg(*ap, uintptr_t);
	flag->num_base = ft_strlen(str);
	flag->num_digits = ft_get_digits(flag);
	if (flag->prec == 0 && flag->num_pointer == 0)
		len += ft_put_space(flag, 2) + write(1, "0x", 2);
	else if (flag->width <= flag->num_digits)
	{
		len += write(1, "0x", 2);
		len += ft_setting_prec_p_u_sx_lx(flag, str);
	}
	else if (flag->flag[E_MINUS])
	{
		len += write(1, "0x", 2);
		len += ft_setting_prec_p_u_sx_lx(flag, str);
		len += ft_put_space(flag, 2);
	}
	else
	{
		len += ft_put_space(flag, 2) + write(1, "0x", 2);
		len += ft_setting_prec_p_u_sx_lx(flag, str);
	}
	return (len);
}
