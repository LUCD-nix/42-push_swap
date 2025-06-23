NAME = push_swap

CFILES = bottom_quicksort.c\
	exit.c\
	free.c\
	helpers.c\
	main.c\
	parser.c\
	pruner.c\
	quicksort.c\
	stack_push.c\
	stack_rotate.c

OBJS := $(CFILES:.c=.o)

CC = cc

LIBFTDIR = libft/

LIBFT := ${LIBFTDIR}libft.a

CFLAGS = -Wall -Wextra -Werror -ggdb

LFLAGS := -I${LIBFTDIR}

all: ${NAME}

${NAME}:  ${OBJS}
	cd ${LIBFTDIR} && make bonus
	${CC} ${OBJS} ${LIBFT} ${LFLAGS} -o ${NAME}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	cd ${LIBFTDIR} && make clean
	rm -f ${OBJS}

fclean: clean
	cd ${LIBFTDIR} && make fclean
	rm -f ${NAME}

re: fclean all

.PHONY: fclean clean all re bonus
