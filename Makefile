NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRCS = test.c
OBJS = ${SRCS:.c=.o}
MLX_DIR = mlx/opengl
MLX_C = -L./mlx/opengl -lmlx -framework OpenGL -framework AppKit
LIBFTPRINTF_DIR = ft_print/
LIBFTPRINTF_C = -L$(LIBFTPRINTF_DIR) -lftprintf

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./mlx/opengl -c $^ -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR) all
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) $(MLX_C) $(LIBFTPRINTF_C) -o $(@) $^

clean :
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re