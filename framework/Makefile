CFLAGS=-Wall -Werror -Wextra
CC=gcc
NAME=libunit.a
SRCS=\
load_test.c \
launch_tests.c \
test_list.c \
ft_func.c \

OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

