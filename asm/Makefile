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

NAME = asm

LEN_NAME = `printf "%s" $(NAME) | wc -c`

DELTA  = $$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

CC = gcc

LIBFT = ../libftprintf/libftprintf.a

SRC =   src/main.c                    \
        src/pars_check_data.c         \
        src/pars_check_instructions.c \
        src/pars_init_data.c          \
        src/pars_lines.c              \
        src/pars_read_file.c          \
        src/pars_separate_lines.c     \
        src/write_code.c              \
        src/write_base_fun.c          \
        src/write_init_mark.c         \
        src/write_code_comand.c       \
        src/write_code_mark.c         \
        src/clean_data.c              \
        src/error_management.c        \

OBJ = $(SRC:.c=.o)

HEADERS = ../libftprintf/get_next_line.h asm.h ../op.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\r\033[48;5;15;38;5;25m✅  MADE $(NAME)  \033[0m\033[K"

$(OBJ): src/%.o: src/%.c
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
