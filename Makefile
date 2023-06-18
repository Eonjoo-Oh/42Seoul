NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CLIB = -L./mlx/opengl -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
SRCS = test.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./mlx/opengl -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) -o $(@) $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re