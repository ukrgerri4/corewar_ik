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

SRC =  src/main.c \
       src/init_function.c \
       src/base_function.c \
       src/pars_alloc_and_free.c \
       src/pars_parsing_file.c \
       src/pars_search_flags.c \
       src/pars_valid_name.c \
       src/pars_move_players_by_n.c \
       src/exec_pc_0.c \
       src/exec_pc_1.c \
       src/f00_helpfun_0.c \
       src/f00_helpfun_1.c \
       src/f00_live.c \
       src/f01_ld.c \
       src/f02_st.c \
       src/f03_add.c \
       src/f04_sub.c \
       src/f05_and.c \
       src/f06_or.c \
       src/f07_xor.c \
       src/f08_zjmp.c \
       src/f09_ldi.c \
       src/f10_sti.c \
       src/f11_fork.c \
       src/f12_lld.c \
       src/f13_lldi.c \
       src/f14_lfork.c \
       src/f15_aff.c \
       src/visual_0.c \
       src/visual_1.c \
       src/visual_2.c \
       src/visual_3_dump.c \
       src/wav_audio.c \

OBJ = $(SRC:.c=.o)

HEADERS = ../libftprintf/get_next_line.h src/vm.h ../op.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lncurses -framework SDL2
	@echo "\r\033[48;5;15;38;5;25m✅  MADE $(NAME)  \033[0m\033[K"

$(OBJ): src/%.o: src/%.c
	@$(CC) -c $(FLAGS) $< -o $@
	@printf "\r\033[38;5;11m⌛ MAKE %s plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

$(LIBFT):
	@make -C ../libftprintf/

libft_clean:
	@make -C ../libftprintf/ clean
	@echo "\r\033[38;5;202m✖ clean libft\033[0m\033[K"

libft_fclean:
	@make -C ../libftprintf/ fclean
	@echo "\r\033[38;5;196m❌ fclean libft\033[0m\033[K"

clean: libft_clean
	@rm -f $(OBJ)
	@echo "\r\033[38;5;202m✖ clean $(NAME)\033[0m\033[K"

fclean: clean libft_fclean
	@rm -f $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K"

re: fclean all
