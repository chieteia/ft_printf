/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:42:33 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/22 18:44:09 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent(t_info *flag)
{
	int i;
	int len;

	i = 1;
	len = 0;
	if (flag->flag[E_MINUS])
	{
		len += ft_put_char('%');
		while (i++ < flag->width)
			len += ft_put_char(' ');
	}
	else if (flag->flag[E_ZERO])
	{
		while (i++ < flag->width)
			len += ft_put_char('0');
		len += ft_put_char('%');
	}
	else
	{
		while (i++ < flag->width)
			len += ft_put_char(' ');
		len += ft_put_char('%');
	}
	return (len);
}
