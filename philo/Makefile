NAME = philo

SRCS = philosophers.c is_valid_digit.c ft_atoi.c routine.c utils.c init_forks.c

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re
