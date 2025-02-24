NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = src/main.c \
       src/utils/list_utils.c \
       src/utils/sort_utils.c \
       src/utils/validation.c \
       src/utils/parse_utils.c \
       src/utils/split_args.c \
       src/operations/push.c \
       src/operations/swap.c \
       src/operations/rotate.c \
       src/operations/reverse_rotate.c \
       src/algorithms/small_sort.c \
       src/algorithms/large_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re