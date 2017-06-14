#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 16:11:32 by apoplavs          #+#    #+#              #
#    Updated: 2017/06/14 21:56:16 by ikryvenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

LEN_NAME = `printf "%s" $(NAME) | wc -c`

DELTA  = $$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

CC = gcc

LIBFT = ../libftprintf/libftprintf.a

SRC =  main.c \
       init_function.c \
       base_function.c \
       pars_alloc_and_free.c \
       pars_parsing_file.c \
       pars_search_flags.c \
       pars_valid_name.c \
       pars_move_players_by_n.c \
       exec_pc_0.c \
       exec_pc_1.c \
       00_helpfun_0.c \
       00_helpfun_1.c \
       00_live.c \
       01_ld.c \
       02_st.c \
       03_add.c \
       04_sub.c \
       05_and.c \
       06_or.c \
       07_xor.c \
       08_zjmp.c \
       09_ldi.c \
       10_sti.c \
       11_fork.c \
       12_lld.c \
       13_lldi.c \
       14_lfork.c \
       15_aff.c \
       visual_0.c \
       visual_1.c \
       visual_2_dump.c \

OBJ = $(SRC:.c=.o)

HEADERS = ../libftprintf/get_next_line.h vm.h ../op.h vm_instructions.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lncurses
	@echo "\r\033[48;5;15;38;5;25m✅  MADE $(NAME)  \033[0m\033[K"
	@rm -f $(OBJ) lem_in.h.gch *~

$(OBJ): %.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

$(LIBFT):
	@make -C ../libftprintf/

libft_clean:
	@make -C ../libftprintf/ clean
	@echo "\r\033[38;5;202m✖ clean libft\033[0m\033[K"

libft_fclean:
	@make -C ../libftprintf/ fclean
	@echo "\r\033[38;5;196m❌ fclean libft\033[0m\033[K"

clean: libft_clean
	@rm -f $(OBJ) lem_in.h.gch *~
	@echo "\r\033[38;5;202m✖ clean $(NAME)\033[0m\033[K"

fclean: clean libft_fclean
	@rm -f $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K"

re: fclean all
