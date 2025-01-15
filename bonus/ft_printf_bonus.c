/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:05:39 by mtice             #+#    #+#             */
/*   Updated: 2025/01/15 19:13:57 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_m(t_flags s_flags, int i, char type, va_list args)
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
		len += ft_print_x_flags(va_arg(args, unsigned int), type, s_flags);
	else if (type == '%')
		len += ft_print_c('%');
	/*else
		len += ft_print_m(s_flags, i, fmt[i], args);*/
	return (len);
}

static void	ft_flags(char type, t_flags *s_flags)
{
	/*if (type == '-')
		s_flags.left_adjust = true;*/
	/*else if (type == '+')
		s_flags.plus = true;
	else if (type == ' ')
		s_flags.space = true;*/
	if (type == '#')
		s_flags->hash = true;
	/*else if (type == '0')
		s_flags.zero = true;
	else if (type = '.')
	{
		s_flags.width = atoi(); //not correct, create function to determine width and length
		s_flags.precision = atoi(); //not correct
	}
	else
		ft_print_m(fmt, i, type, args); //check if logic is correct*/
}

static int	ft_print_b(const char *fmt, int i, va_list args)
{
	t_flags	s_flags;
	int	len;

	len = 0;
	while (fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' ' 
			|| fmt[i] == '#' || fmt[i] == '0' || fmt[i] == '.')
	{
		ft_flags(fmt[i], &s_flags);
		i++;
	}
	if (fmt[i] == 'c' || fmt[i] == 's' || fmt[i] == 'p' || fmt[i] == 'd' 
			|| fmt[i] == 'i' || fmt[i] == 'u' || fmt[i] == 'x' || fmt[i] == 'X')
		len += ft_print_m(s_flags, i, fmt[i], args);
	else
		return (0);
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
			len += ft_print_b(fmt, i + 1, args);
			i++;
		}
		else
			len += ft_print_c(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int result;
	int result2;

	result = ft_printf("Hello %#x World!", 123);
	printf("\n%d", result);
	//result2 = printf("%p", p);
	//printf("%d", result2);
	return (0);
}
