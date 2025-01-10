/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:50:14 by mtice             #+#    #+#             */
/*   Updated: 2025/01/10 16:50:14 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//libraries to include
# include <stdarg.h>
# include <unistd.h>

//libraries to remove
# include <stdio.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(void *p, char type);
int	ft_print_di(int n);
int	ft_print_u(unsigned int u);
int	ft_print_x(unsigned long x, char type);

#endif
