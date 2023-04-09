NAME = push_swap
CC = CC
CFLAGS = -Wall -Wextra -Werror
#INCLUDES는 헤더파일 폴더 따로 지정안되어있으면 필요없음?
SRCS = check_error.c count.c find.c first_stack.c ft_split.c is_utils.c make_utils.c pivot.c push_swap.c push.c rev_rot.c rotate.c sort_do.c sort_few.c sort.c swap.c utils.c
OBJS = ${SRCS:.c=.o}
#여기까지가 매크로설정부분

all = ${NAME}
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf ${OBJS}

fclean :

re : fclean all

.PHONY : all clean fclean re