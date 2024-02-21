SRC = push_swap.c sort_3_numbers.c sort_less_than_10_numbers.c make_move.c sort_big_numbers.c make_move_for_big.c
BSRC = checker.c checker_utils.c
GSRC = check_args.c check_args_utils.c actions.c actions_2.c actions_3.c ft_atol.c extract_args.c linked_list_stuff.c linked_list_stuff_2.c

SRC_DIR = src/
OBJ_DIR = obj/

OSRC=$(addprefix $(SRC_DIR), $(SRC))
OBSRC=$(addprefix $(SRC_DIR), $(BSRC))
OGSRC=$(addprefix $(SRC_DIR), $(GSRC))

NAME= push_swap
BONUS= checker
INCLUDE = -I. -I libft -I includes

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): ascii $(OSRC) $(OGSRC)
	@make -C libft > /dev/null
	@$(CC) -Wall -Wextra -Werror $(INCLUDE) $(OSRC) $(OGSRC) libft/libft.a -o $@

bonus: ascii $(OBSRC) $(OGSRC)
	@make -C libft > /dev/null
	@$(CC) -Wall -Wextra -Werror $(INCLUDE) $(OBSRC) $(OGSRC) libft/libft.a -o $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -Wall -Wextra -Werror -c $< -o $@ $(INCLUDE)

clean:
	@make -C libft clean
	@rm -rf *.o

fclean:
	@make -C libft fclean
	@rm -rf *.o $(NAME) $(BONUS)

re:fclean all


ascii:
	@clear
	@printf "$(GREEN)\
                                                                                                                                                                   \n\
PPPPPPPPPPPPPPPPP                                     hhhhhhh                SSSSSSSSSSSSSSS                                                                       \n\
P::::::::::::::::P                                    h:::::h              SS:::::::::::::::S                                                                      \n\
P::::::PPPPPP:::::P                                   h:::::h             S:::::SSSSSS::::::S                                                                      \n\
PP:::::P     P:::::P                                  h:::::h             S:::::S     SSSSSSS                                                                      \n\
  P::::P     P:::::Puuuuuu    uuuuuu      ssssssssss   h::::h hhhhh       S:::::S      wwwwwww           wwwww           wwwwwwwaaaaaaaaaaaaa  ppppp   ppppppppp   \n\
  P::::P     P:::::Pu::::u    u::::u    ss::::::::::s  h::::hh:::::hhh    S:::::S       w:::::w         w:::::w         w:::::w a::::::::::::a p::::ppp:::::::::p  \n\
  P::::PPPPPP:::::P u::::u    u::::u  ss:::::::::::::s h::::::::::::::hh   S::::SSSS     w:::::w       w:::::::w       w:::::w  aaaaaaaaa:::::ap:::::::::::::::::p \n\
  P:::::::::::::PP  u::::u    u::::u  s::::::ssss:::::sh:::::::hhh::::::h   SS::::::SSSSS w:::::w     w:::::::::w     w:::::w            a::::app::::::ppppp::::::p\n\
  P::::PPPPPPPPP    u::::u    u::::u   s:::::s  ssssss h::::::h   h::::::h    SSS::::::::SSw:::::w   w:::::w:::::w   w:::::w      aaaaaaa:::::a p:::::p     p:::::p\n\
  P::::P            u::::u    u::::u     s::::::s      h:::::h     h:::::h       SSSSSS::::Sw:::::w w:::::w w:::::w w:::::w     aa::::::::::::a p:::::p     p:::::p\n\
  P::::P            u::::u    u::::u        s::::::s   h:::::h     h:::::h            S:::::Sw:::::w:::::w   w:::::w:::::w     a::::aaaa::::::a p:::::p     p:::::p\n\
  P::::P            u:::::uuuu:::::u  ssssss   s:::::s h:::::h     h:::::h            S:::::S w:::::::::w     w:::::::::w     a::::a    a:::::a p:::::p    p::::::p\n\
PP::::::PP          u:::::::::::::::uus:::::ssss::::::sh:::::h     h:::::hSSSSSSS     S:::::S  w:::::::w       w:::::::w      a::::a    a:::::a p:::::ppppp:::::::p\n\
P::::::::P           u:::::::::::::::us::::::::::::::s h:::::h     h:::::hS::::::SSSSSS:::::S   w:::::w         w:::::w       a:::::aaaa::::::a p::::::::::::::::p \n\
P::::::::P            uu::::::::uu:::u s:::::::::::ss  h:::::h     h:::::hS:::::::::::::::SS     w:::w           w:::w         a::::::::::aa:::ap::::::::::::::pp  \n\
PPPPPPPPPP              uuuuuuuu  uuuu  sssssssssss    hhhhhhh     hhhhhhh SSSSSSSSSSSSSSS        www             www           aaaaaaaaaa  aaaap::::::pppppppp    \n\
                                                                                                                                                p:::::p            \n\
                                                                                                                                 $(RED)by: abouabra$(GREEN)   p:::::p            \n\
                                                                                                                                               p:::::::p           \n\
                                                                                                                                               p:::::::p           \n\
                                                                                                                                               p:::::::p           \n\
                                                                                                                                               ppppppppp           \n\
                                                                                                                                                                   $(RESET)\n"



.PHONY: all clean fclean re $(BONUS)
