/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:35:02 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/24 05:02:52 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_s(t_info *flag, va_list *ap)
{
	int		len;
	int		space_len;
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	len = (flag->prec == DEFAULT || ft_strlen(str) < flag->prec) ?
	ft_strlen(str) : flag->prec;
	space_len = flag->width - len;
	if (flag->flag[E_MINUS])
	{
		write(1, str, len);
		while (space_len-- > 0)
			ft_put_char(' ');
	}
	else
	{
		while (space_len-- > 0)
			(flag->flag[E_ZERO]) ? ft_put_char('0') : ft_put_char(' ');
		write(1, str, len);
	}
	return ((len > flag->width) ? len : flag->width);
}
