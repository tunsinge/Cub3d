# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:33:23 by mdoumi            #+#    #+#              #
#    Updated: 2023/05/02 18:57:11 by mdoumi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	./src/main.c \
		./src/ft_strcmp.c \
		./src/ft_strlen.c \
		./src/ft_substr.c \
		./src/error.c \
		./src/parsing.c \
		./src/GNL/get_next_line_bonus.c \
		./src/GNL/get_next_line_utils_bonus.c \
		./src/check_map.c \
		./src/quit.c
INC = -I ./include
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror -g3
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) libmlx42.a $(OBJS) $(INC) -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INC}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
