/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:01:32 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/27 22:14:11 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_c(t_info *flag, va_list *ap)
{
	char	c;
	int		i;
	int		len;

	i = 1;
	len = 0;
	c = (unsigned char)va_arg(*ap, int);
	if (flag->flag[E_MINUS])
	{
		len += ft_put_char(c);
		while (i++ < flag->width)
			len += ft_put_char(' ');
	}
	else
	{
		while (i++ < flag->width)
			len += ft_put_char(' ');
		len += ft_put_char(c);
	}
	return (len);
}
