/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:16:28 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/23 23:54:13 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_flag(t_info *material)
{
	material->flag[E_MINUS] = 0;
	material->flag[E_ZERO] = 0;
	material->width = DEFAULT;
	material->prec = DEFAULT;
	material->specifier = DEFAULT;
	material->num_int = 0;
	material->num_uint = 0;
	material->num_pointer = 0;
	material->num_digits = 0;
	material->num_base = 0;
}
