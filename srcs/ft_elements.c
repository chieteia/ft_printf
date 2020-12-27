/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:15:02 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/25 10:52:51 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int		ft_put_char(int c)
{
	return (write(1, &c, 1));
}

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
