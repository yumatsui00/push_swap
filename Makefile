SRCS = 0_main.c 1_check_args.c 2_arr2node.c 3_pushswap.c 4_sort_3_mixed.c \
	8_a_sorter.c 9_control1.c 9_control2.c 9_error.c 3_1_check_if_sorted.c \
	3_2_nums_list_utils.c 1_check_if_split.c

SRCS_BONUS = bonus_0.c bonus_1.c bonus_2.c bonus_3.c bonus_9_control1.c \
	bonus_9_control2.c bonus_9_error.c bonus_gnl.c bonus_gnl_utils.c bonus_1_1.c

NAME_MAN = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -Wall -Wextra -Werror -fsanitize=address -g
OBJC = $(SRCS:.c=.o)
OBJC_BONUS = $(SRCS_BONUS:.c=.o)
RM = rm -f

ifeq ($(MAKECMDGOALS), bonus)
	OBJ = $(OBJC_BONUS)
	NAME = $(NAME_BONUS)
else
	OBJ = $(OBJC)
	NAME = $(NAME_MAN)
endif


all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OBJ)
	$(CC) $(DEBUG) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJC) $(OBJC_BONUS)

fclean: clean
	$(RM) $(NAME_MAN) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
