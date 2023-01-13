SRC = push_swap.c sort_3_numbers.c sort_less_than_10_numbers.c make_move.c sort_big_numbers.c make_move_for_big.c
BSRC = checker.c checker_utils.c
GSRC = check_args.c check_args_utils.c actions.c actions_2.c actions_3.c ft_atol.c extract_args.c linked_list_stuff.c linked_list_stuff_2.c

OSRC=$(SRC:.c=.o)
OBSRC=$(BSRC:.c=.o)
OGSRC=$(GSRC:.c=.o)

AR= ar -rcs
NAME= push_swap
BONUS= checker
INCLUDE = -I. -I libft

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OSRC) $(OGSRC)
	@make -C libft
	@$(CC) -Wall -Wextra -Werror $(INCLUDE) $^ libft/libft.a -o $@
	@printf "$(RED)--------PUSH SWAP DONE--------$(RESET)\n"

bonus: $(OBSRC) $(OGSRC)
	@make -C libft
	@$(CC) -Wall -Wextra -Werror $(INCLUDE) $^ libft/libft.a -o $(BONUS)
	@printf "$(BLUE)--------CHECKER DONE--------$(RESET)\n"

%.o : %.c
	@printf "hana kan compili f$(GREEN) $< $(RESET) \n"
	@$(CC) -Wall -Wextra -Werror -c $<

clean:
	@make -C libft clean
	@rm -rf *.o

fclean:
	@make -C libft fclean
	@rm -rf *.o $(NAME) $(BONUS)

re:fclean all

.PHONY: all clean fclean re $(BONUS)
