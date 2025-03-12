# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtice <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:51:38 by mtice             #+#    #+#              #
#    Updated: 2025/02/05 18:40:28 by mtice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SOURCES := 	ft_printf.c \
			ft_print_c.c \
			ft_print_s.c \
			ft_print_p.c \
			ft_print_di.c \
			ft_print_u.c \
			ft_print_x.c \
			ft_struct.c \
			ft_utils.c

SOURCES_BONUS := 	ft_printf_bonus.c \
					ft_print_c_bonus.c \
					ft_print_s_bonus.c \
					ft_print_p_bonus.c \
					ft_print_di_bonus.c \
					ft_print_u_bonus.c \
					ft_print_x_bonus.c \
					ft_struct_bonus.c \
					ft_utils_bonus.c

OBJECTS := $(SOURCES:.c=.o)

OBJECTS_BONUS := $(SOURCES_BONUS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror


AR := ar
ARFLAGS := -rcs

RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

all: $(NAME)

bonus: $(OBJECTS_BONUS)
	$(AR) $(ARFLAGS) hello.a $(OBJECTS_BONUS)
	mv hello.a $(NAME)
clean:
	$(RM) $(OBJECTS)

clean_bonus: 
	$(RM) $(OBJECTS_BONUS)

fclean:	clean clean_bonus
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean clean_bonus fclean re	
