NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
#INCLUDES는 폴더 지정따로 안하면 안넣어도 되는 것?
SRCS = check_error.c count.c find.c first_stack.c ft_split.c is_utils.c make_utils.c \
	pivot.c push_swap.c push.c rev_rot.c rotate.c sort_do.c sort_few.c
OBJS = ${SRCS:.c=.o}
#여기까지가 매크로설정구간

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) ${NAME} ${OBJS}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -f ${NAME}

re : clean all

.PHONY : clean fclean re