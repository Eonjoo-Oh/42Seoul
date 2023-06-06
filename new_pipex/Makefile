NAME = pipex
BONUS_NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRCS = pipex.c \
		init_arg.c pipex_utils.c ft_split.c \
		get_cmd.c do_cmd.c \

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c \
			pipex_bonus.c heredoc_bonus.c do_cmd_bonus.c\
			pipex_utils.c \

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all : $(NAME)
bonus : $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus