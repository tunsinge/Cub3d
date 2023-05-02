NAME = cub3D
SRCS =	./src/main.c \
		./src/ft_strcmp.c \
		./src/ft_strlen.c \
		./src/ft_substr.c
INC = -I ./include
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INC)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INC}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
