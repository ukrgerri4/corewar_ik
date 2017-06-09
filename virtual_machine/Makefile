#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 16:11:32 by apoplavs          #+#    #+#              #
#    Updated: 2017/05/05 10:51:03 by apoplavs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

LEN_NAME = `printf "%s" $(NAME) | wc -c`

DELTA  = $$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

CC = gcc

LIBFT = ../libftprintf/libftprintf.a

SRC =   main.c \
		allocation_memory.c \
		free_memory.c \
		ft_error.c \
		ft_parsing_file.c \
		ft_move_players_by_n.c \
		ft_search_flags.c \
		ft_valid_name.c \
		ik_base_function.c \
		ik_init_pc.c \
		ik_start_pc.c \
		ik_start_pc_functions.c \
		ik_init_visualization.c \
		ik_visualization.c \
		ik_init_function.c \
		support_instructions.c \
		checking_instructions.c \
		instruction_live.c \
		instruction_ld.c \
		instruction_st.c \
		instruction_add.c \
		instruction_sub.c \
		instruction_and.c \
		instruction_or.c \
		instruction_xor.c \
		instruction_zjmp.c \
		instruction_ldi.c \
		instruction_sti.c \
		instruction_fork.c \
		instruction_lld.c \
		instruction_lldi.c \
		instruction_lfork.c \
		instruction_aff.c \

OBJ = $(SRC:.c=.o)

HEADERS = ../libftprintf/get_next_line.h virtual_machine.h ../op.h instructions.h

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) -lncurses
	@echo "\r\033[48;5;15;38;5;25m✅  MADE $(NAME)  \033[0m\033[K"
	@make clean

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
