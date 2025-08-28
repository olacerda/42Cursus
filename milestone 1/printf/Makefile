# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 15:33:12 by otlacerd          #+#    #+#              #
#    Updated: 2025/06/05 17:09:27 by otlacerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = \
	ft_printf.c \
	functions/c_print.c \
	functions/d_print.c \
	functions/i_print.c \
	functions/p_print.c \
	functions/perc_print.c \
	functions/s_print.c \
	functions/u_print.c \
	functions/x_print.c \
	functions/x_up_print.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $^

funcoes/%.o: funcoes/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re