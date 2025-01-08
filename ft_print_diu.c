/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:29:44 by mtice             #+#    #+#             */
/*   Updated: 2025/01/08 14:47:02 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_digits(long n)
{
	int	digits;

	digits = 0;
	if (n == -2147483648)
		digits += 11;
	else if (n < 0)
	{
		digits += 1;
		n = n * (-1);
	}
	else if (n == 0)
		digits += 1;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	ft_print_di(int n)
{
	char	val;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (ft_digits((long)n));
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		val = n + '0';
		write(1, &val, 1);
	}
	else if (n > 9)
	{
		val = n % 10 + '0';
		ft_print_di(n / 10);
		write(1, &val, 1);
	}
	return (ft_digits((long)n));
}

int	ft_print_u(unsigned int u)
{
	char	val;

	if (u >= 0 && u <= 9)
	{
		val = u + '0';
		write(1, &val, 1);
	}
	else if (u > 9)
	{
		val = u % 10 + '0';
		ft_print_u(u / 10);
		write(1, &val, 1);
	}
	return (ft_digits((long)u));
}
