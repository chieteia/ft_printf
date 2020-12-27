/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:00:56 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 05:11:53 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_str_to_num(t_info *flag, va_list *ap, const char **fmt,
														int dot_flag)
{
	long long num;

	num = -1;
	if (**fmt == '*')
	{
		num = va_arg(*ap, int);
		if ((num < 0) && dot_flag)
			num = -1;
		else if (num < 0)
		{
			num *= -1;
			flag->flag[E_MINUS] = 1;
			flag->flag[E_ZERO] = 0;
		}
		(*fmt)++;
	}
	else if (dot_flag || ft_isdigit(**fmt))
	{
		num = 0;
		while (ft_isdigit(**fmt))
			num = 10 * num + (*(*fmt)++ - '0');
	}
	return (num);
}
