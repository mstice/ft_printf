# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtice <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:51:38 by mtice             #+#    #+#              #
#    Updated: 2025/01/10 17:29:01 by mtice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SOURCES := 	ft_printf.c \
			ft_print_cs.c \
			ft_print_diu.c \
			ft_print_xp.c
				

OBJECTS := $(SOURCES:.c=.o)

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

clean:
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re	
