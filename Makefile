NAME = push_swap
BONUS_NAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
RM = rm -rf
#INCLUDES는 헤더파일 폴더 따로 지정안되어있으면 필요없음?
SRCS = push_swap.c check_error.c count.c find.c first_stack.c ft_split.c \
		is_utils.c make_utils.c pivot.c \
		sort_do.c sort_few.c sort.c utils.c\
		push.c rev_rot.c rotate.c swap.c
OBJS = ${SRCS:.c=.o}
BONUS_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c\
			push_swap_bonus.c \
			push_bonus.c swap_bonus.c rotate_bonus.c rev_rot_bonus.c\
			count.c check_error.c first_stack.c ft_split.c is_utils.c make_utils.c\
			find.c utils.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
#여기까지가 매크로설정부분

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

fclean :
	$(MAKE) clean
	$(RM) $(NAME) $(BONUS_NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus