NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRCS = pipex.c \
		pipex_utils.c ft_split.c \
		get_cmd.c do_cmd.c \

OBJS = ${SRCS:.c=.o}

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	$(RM) $(OBJS)
fclean : 
	$(MAKE) clean
	$(RM) $(NAME)
re :
	fclean all

.PHONY : all clean fclean re