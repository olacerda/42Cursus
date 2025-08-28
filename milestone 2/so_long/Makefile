#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 13:48:28 by olacerda          #+#    #+#              #
#    Updated: 2025/08/27 07:07:29 by olacerda         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_SO_LONG = so_long.exe
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC_SO_LONG = \
	so_long.c \

OBJ_SO_LONG = $(SRC_SO_LONG:.c=.o)

all: $(NAME_SO_LONG)

$(NAME_SO_LONG): $(OBJ_SO_LONG)
	$(CC) $(CFLAGS) $(OBJ_SO_LONG) -o $(NAME_SO_LONG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SO_LONG)

fclean: clean
	rm -f $(NAME_SO_LONG) $(OBJ_SO_LONG)

re: fclean all

.PHONY: all clean fclean re