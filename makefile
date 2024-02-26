SRCS := src/push_swap.c\
		src/actions.c\
		src/algo.c\
		src/big_sort.c\
		src/lists01.c\
		src/lists02.c\
		src/mini_sort.c\
		src/parcing01.c\
		src/parcing02.c\
		src/sort_tools00.c\
		src/sort_tools01.c\
		src/sort_tools02.c

BONUS := bonus/checker.c\
		src/actions.c\
		src/algo.c\
		src/big_sort.c\
		src/lists01.c\
		src/lists02.c\
		src/mini_sort.c\
		src/parcing01.c\
		src/parcing02.c\
		src/sort_tools00.c\
		src/sort_tools01.c\
		src/sort_tools02.c\
		bonus/get_next_line.c\
		bonus/get_next_line_utils.c

FLAGS := -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS:.c=.o)
NAME := push_swap
check := checker
RM := rm -f

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

$(check): $(BONUS_OBJS)
	cc $(FLAGS) $(BONUS_OBJS) -o $(check)

all: $(NAME)

bonus:	$(check)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(check) 

re: fclean all

.PHONY: all clean fclean re
