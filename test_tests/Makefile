NAME=strlen_unit_test
CC=gcc
CFLAGS=-I$(FRAMEWORK_DIR)
FRAMEWORK_DIR=../framework
LIBUNIT=$(FRAMEWORK_DIR)/libunit.a
SRCS=\
main.c \
00_launcher.c \
basic_test.c \
null_test.c \
bus_error.c \
segv.c \

OBJS=$(SRCS:.c=.o)

.PHONY: test all clean fclean re

test: $(NAME)
	./$(NAME); echo $${?}

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBUNIT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBUNIT):
	make -C $(FRAMEWORK_DIR)
