NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c\
so_long.c utils.c free.c\
map_main.c map_validate.c map_bfs.c queue.c map_utils.c\
render_image.c\
key_hook_main.c key_hook.c key_hook_utils.c

OBJS = ${SRCS:.c=.o}
MLX_DIR = ./mlx/opengl
MLX_C = -L./mlx/opengl -lmlx -framework OpenGL -framework AppKit
LIBFTPRINTF_DIR = ./ft_printf/
LIBFTPRINTF_C = -L$(LIBFTPRINTF_DIR) -lftprintf

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./mlx/opengl -c $^ -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(LIBFTPRINTF_DIR) all
	$(CC) $(CFLAGS) $(MLX_C) $(LIBFTPRINTF_C) -o $(@) $^

clean :
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re