NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = push_swap.c check_error.c count.c find.c first_stack.c ft_split.c \
		is_utils.c make_utils.c pivot.c free.c\
		sort_do.c sort_few.c sort.c utils.c\
		push.c rev_rot.c rotate.c swap.c
OBJS = ${SRCS:.c=.o}
BONUS_SRCS = libft/get_next_line.c libft/get_next_line_utils.c\
			push_swap_bonus.c \
			push_bonus.c swap_bonus.c rotate_bonus.c rev_rot_bonus.c\
			count.c check_error.c first_stack.c ft_split.c is_utils.c make_utils.c\
			find.c utils.c free.c
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
	$(RM) $(OBJS) $(BONUS_OBJS) $(MAIN_OBJS) $(B_MAIN_OBJS)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re bonus