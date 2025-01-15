/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:51:59 by mtice             #+#    #+#             */
/*   Updated: 2025/01/10 16:55:06 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *p, char type)
{
	unsigned long	address;
	int				length;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)p;
	write(1, "0x", 2);
	length = ft_print_x(address, type) + 2;
	return (length);
}

int	ft_print_x(unsigned long x, char type)
{
	unsigned long	t;
	char			*base;
	static int		l;

	t = x;
	l = 0;
	if (type == 'x' || type == 'p')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (t >= 0 && t < 16)
	{
		write(1, &base[t], 1);
		l++;
	}
	else if (t >= 16)
	{
		ft_print_x(t / 16, type);
		write(1, &base[t % 16], 1);
		l++;
	}
	return (l);
}
/*
int    main(void)
{
    int x = 42;
	int *ptr = &x;
	int result;

    result = ft_print_p((void *)ptr, 'p');
    printf("\n%d", result);
	printf("\nprintf:%p", (void *)ptr);
    return (0);
}*/
