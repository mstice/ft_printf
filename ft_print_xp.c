/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:51:59 by mtice             #+#    #+#             */
/*   Updated: 2025/01/08 20:09:16 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//int	ft_print_p(void *p);

int	ft_print_x(unsigned int x, char type)
{
	long	t;
	char	*base;
	char	val;

	t = x;
	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (t >= 0 && t < 16)
	{
		val = base[t];
		write(1, &val, 1);
	}
	else if (t >= 16)
	{
		ft_print_x(t / 16, type);
		write(1, &base[t % 16], 1);
	}
	return (2);
}

int	main(void)
{
	int	result;

	result = ft_print_x(123, 'X');
	printf("\n%i", result);
	return (0);
}
