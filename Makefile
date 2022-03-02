CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM=rm -f
NAME=pipex
SRCS=ft_calloc.c \
	 ft_main.c \
	 ft_pipex.c \
	 ft_split.c \
	 ft_strdup.c \
	 ft_strjoin.c \
	 ft_strlen.c \
	 ft_substr.c \
	 ft_checks.c

OBJS=${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
