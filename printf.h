/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:50:14 by mtice             #+#    #+#             */
/*   Updated: 2025/01/08 18:58:33 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//libraries to include
# include <stdarg.h>
# include <unistd.h>

//libraries to remove
# include <stdio.h>

int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(void *p);
int	ft_print_di(int n);
int	ft_print_u(unsigned int u);
int	ft_print_x(unsigned int x, char type);

//Functions from libft
//size_t ft_strlen(const char *s);
//char *ft_strdup(const char *s);

#endif
