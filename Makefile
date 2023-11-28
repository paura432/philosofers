NAME = philo

MY_SOURCES = philo.c init_data.c utils.c list.c threads.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibreria #-g3 -fsanitize=address

all: ${NAME}
${NAME}: ${MY_OBJECTS}
	@${CC} ${CFLAGS} ${MY_OBJECTS} -o ${NAME}

clean:
		rm -f $(MY_OBJECTS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
