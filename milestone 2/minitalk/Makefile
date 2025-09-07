# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 20:34:35 by otlacerd          #+#    #+#              #
#    Updated: 2025/09/01 19:42:03 by otlacerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

OBJ_DIR = objt/

SRC_SERVER = \
	server.c \

SRC_CLIENT = \
	client.c \

SRCS = $(SRC_SERVER) $(SRC_CLIENT)

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ = ($(SRCS)%.c,$(OBJ_DIR)%.o)

all: $(NAME_SERVER) $(NAME_CLIENT) $(OBJ)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(OBJ_DIR)%.o: $(SRCS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT)

re: fclean all

.PHONY: all clean fclean re