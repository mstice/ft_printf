/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:58:22 by mtice             #+#    #+#             */
/*   Updated: 2025/01/10 17:12:40 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_fmt(const char *fmt, int i, char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (type == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_p(va_arg(args, void *), type);
	else if (type == 'd' || type == 'i')
		len += ft_print_di(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_u(va_arg(args, int));
	else if (type == 'x' || type == 'X')
		len += ft_print_x(va_arg(args, unsigned int), type);
	else if (type == '%')
		len += ft_print_c('%');
	else
		len += ft_print_fmt(fmt, i, fmt[i], args);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, fmt);
	if (fmt[i] == '\0')
		return (0);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			len += ft_print_fmt(fmt, i, fmt[i + 1], args);
			i++;
		}
		else
			len += ft_print_c(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int a = 12;
	int	b = 123;
	int c = 123456789;
	int	result;
	int result2;
	void *p;

	p = NULL;
	result = ft_printf("Hello World!");
	printf("\n%d", result);
	//result2 = printf("%p", p);
	//printf("%d", result2);
	return (0);
}*/