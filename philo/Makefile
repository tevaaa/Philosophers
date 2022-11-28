RM = rm -f

SRC = philo.c utils.c parsing.c forks.c actions.c

OBJS = ${SRC:.c=.o}

NAME = philo

CC = gcc -Wall -Wextra -Werror

all:${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
	$(CC) $(OBJS) -pthread -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all