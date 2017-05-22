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

SRC =   main.c \
        error_management.c \
        init_data.c \
        check_data.c \
        read_file.c \
        parse_lines.c \
        clean_data.c ik_1.c \
        check_instructions.c \
        ik_1.c \
        ik_2.c \
        ik_print_memory.c \
        ik_init_struct.c \
        ik_write_comand.c \
        ik_write_mark.c

OBJ = $(SRC:.c=.o)

HEADERS = ../libftprintf/get_next_line.h asm.h ../op.h

FLAGS = -Wall -Wextra 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\r\033[48;5;15;38;5;25m✅  MADE $(NAME)  \033[0m\033[K"

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
