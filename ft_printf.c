/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:58:22 by mtice             #+#    #+#             */
/*   Updated: 2025/01/08 20:09:57 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_fmt(const char *fmt, char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (type == 's')
		len += ft_print_s(va_arg(args, char *));
	/*else if (type == 'p')
		len += ft_print_p(va_arg(args, void *));*/
	else if (type == 'd' || type == 'i')
		len += ft_print_di(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_u(va_arg(args, int));
	else if (type == 'x' || type == 'X')
		len += ft_print_x(va_arg(args, unsigned int), type);
	else if (type == '%')
		len += ft_print_c('%');
	/*else
		len+= ft_print_c('%');*/
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
			len += ft_print_fmt(fmt, fmt[i + 1], args);
			i++;
		}
		else
			len += ft_print_c(fmt[i]);
		i++;
	}
	return (len);
}

int	main(void)
{
	int	c = 123;

	ft_printf("Hello, %x\n", c);
	return (0);
}
