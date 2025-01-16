/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:06:20 by mtice             #+#    #+#             */
/*   Updated: 2025/01/15 18:29:36 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

//libraries to remove
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags
{
	bool	left_adjust;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
	int		width;
	int		precision;
}				t_flags;

int	ft_printf(const char *fmt, ...);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(void *p, char type);
int	ft_print_di(int n);
int	ft_print_u(unsigned int u);
int	ft_print_x(unsigned long x, char type);

//int	ft_print_c_flags(char c, t_flags s_flags);
//int	ft_print_s_flags(char *s, t_flags s_flags);
//int	ft_print_p_flags(void *pm char type, t_flags s_flags);
//int	ft_print_di_flags(int n, t_flags s_flags);
//int	ft_print_u_flags(unsigned int u, t_flags s_flags);
int ft_print_x_flags(unsigned long x, char type, t_flags s_flags);

#endif
