NAME = push_swap
BONUS_NAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
#INCLUDES는 헤더파일 폴더 따로 지정안되어있으면 필요없음?
SRCS = check_error.c count.c find.c first_stack.c ft_split.c \
		is_utils.c make_utils.c pivot.c push.c rev_rot.c rotate.c \
		sort_do.c sort_few.c sort.c swap.c utils.c
MAIN_SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}
MAIN_OBJS = ${MAIN_SRCS:.c=.o}
BONUS_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
B_MAIN_SRCS = bonus_checker.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
B_MAIN_OBJS = ${B_MAIN_SRCS:.c=.o}
#여기까지가 매크로설정부분

all : $(NAME)

bonus : $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME) : $(OBJS) $(BONUS_OBJS) $(B_MAIN_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RM) $(OBJS) $(BONUS_OBJS) $(MAIN_OBJS) $(B_MAIN_OBJS)

fclean : clean
	$(MAKE) clean
	$(RM) $(NAME) $(BONUS_NAME)

re : all fclean
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re