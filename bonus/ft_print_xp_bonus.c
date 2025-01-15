/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:36:34 by mtice             #+#    #+#             */
/*   Updated: 2025/01/15 18:59:02 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int ft_print_x_flags(unsigned long x, char type, t_flags s_flags)
{
	if (s_flags.hash == true && type == 'X')
		write(1, "0X", 2);
	else if (s_flags.hash == true && type == 'x')
		write(1, "0x", 2);
	else if (s_flags.hash != true && (type == 'x' || type == 'X'))
		return (ft_print_x(x, type));
	else
		return (0);
	return(2 + ft_print_x(x, type));
}

/*
int    main(void)
{
	int result;
	t_flags s_flags;

	s_flags.hash = true;
    result = ft_print_x_flags(123, 'X', s_flags);
    printf("\n%d", result);
	//printf("\nprintf:%p", (void *)ptr);
    return (0);
}*/
