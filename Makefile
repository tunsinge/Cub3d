# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:23:53 by Foxan             #+#    #+#              #
#    Updated: 2023/05/18 14:33:39 by mdoumi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD			:= \033[1m
BLACK			:= \033[30;1m
RED				:= \033[31;1m
GREEN			:= \033[32;1m
YELLOW			:= \033[33;1m
BLUE			:= \033[34;1m
MAGENTA			:= \033[35;1m
CYAN			:= \033[36;1m
WHITE			:= \033[37;1m
RESET			:= \033[0m

#//= Variables =//#
CC				:= gcc
NAME			:= cub3d
PROJECT_NAME	:= CUB3D
#SRCS = ./src/raycasting.c
SRCS			:=	./src/main.c \
					./src/check_map.c \
					./src/error.c \
					./src/ft_atoi.c \
					./src/ft_split.c \
					./src/ft_strdup.c \
					./src/ft_strcmp.c \
					./src/ft_strlen.c \
					./src/ft_substr.c \
					./src/parsing.c \
					./src/parsing_utils.c \
					./src/quit.c \
					./src/raycast.c \
					./src/render.c \
					./src/utils.c \
					./src/GNL/get_next_line_bonus.c \
					./src/GNL/get_next_line_utils_bonus.c
INCLUDES		:= -I ./include
FLAGS			:= -g -g3
OBJS			:= ${SRCS:.c=.o}
SOMETHING		:= 0
LIBMLX			:= ./MLX42
LIBGLFW 		:= -L "/Users/$$USER/.brew/opt/glfw/lib/"
LIBS			:= $(LIBMLX)/libmlx42.a -lglfw -lm

#//= Main compiling rules =//#

all: libmlx startall ${NAME} endall

${NAME}: ${OBJS}
	@$(CC) -o $(NAME) $(OBJS) $(LIBS) $(LIBGLFW) $(INCLUDES)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INCLUDES} &&  printf "$(MAGENTA)$(PROJECT_NAME)$(RESET)$(BOLD) Compiling: $(notdir $<) \n$(RESET)"
	@$(eval SOMETHING = 1)

libmlx:
	@printf "$(MAGENTA)Making MLX...\n$(RESET)" && $(MAKE) -C $(LIBMLX)
	@printf "$(BOLD)Done making $(MAGENTA)MLX\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

#//= Cleaning rules =//#

clean:
	@$(MAKE) -C $(LIBMLX) clean
	@rm -f ${OBJS} && printf "$(GREEN)Cleaning $(PROJECT_NAME) OBJS...\n$(RESET)"
	@printf "$(YELLOW)Finished cleaning !\n$(RESET)"
	@printf "$(YELLOW)--------------------\n$(RESET)"

fclean: clean cleanhistory # cleaning rule
	@$(MAKE) -C $(LIBMLX) fclean
	@rm -f ${NAME} && printf "$(GREEN)Cleaning $(PROJECT_NAME) $(NAME)...\n$(RESET)"
	@printf "$(YELLOW)Finished cleaning everything !\n$(RESET)"
	@printf "$(YELLOW)--------------------\n$(RESET)"

cleanhistory:
	@rm -f ${HISTORY_PATH} && printf "$(GREEN)Cleaning $(PROJECT_NAME) $(HISTORY_PATH)...\n$(RESET)"
	@printf "$(YELLOW)Finished cleaning !\n$(RESET)"
	@printf "$(YELLOW)--------------------\n$(RESET)"

#//= Beautification rules =//#

startall:
	@printf "$(BOLD)--------------------\n$(RESET)"
	@printf "$(MAGENTA)Starting doing everything\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

endall:
	@if [ $(SOMETHING) = 1 ]; then printf "$(BOLD)Done compiling $(MAGENTA)e$(CYAN)v$(GREEN)e$(YELLOW)r$(BLUE)y$(RED)t$(MAGENTA)h$(CYAN)i$(GREEN)n$(YELLOW)g !\n$(RESET)$(BOLD)--------------------\n$(RESET)$(MAGENTA)Done making $(PROJECT_NAME)!\n$(RESET)"; fi
	@if [ $(SOMETHING) = 0 ]; then printf "$(MAGENTA)Nothing to do !\n$(RESET)"; fi

re:	fclean all

.PHONY: all clean fclean re start end startall endall libmlx
