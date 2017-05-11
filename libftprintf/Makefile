#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 13:38:47 by apoplavs          #+#    #+#              #
#    Updated: 2017/03/01 13:38:49 by apoplavs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LEN_NAME = `printf "%s" $(NAME) | wc -c`

DELTA  = $$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

CC = gcc

LIB_PATH = ./libft/

LIB = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
 ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c\
 ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
 ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
 ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
 ft_putstr.c ft_putstr_fd.c ft_sort_tab.c ft_strcat.c\
 ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
 ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c\
 ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c

SRC_NAME = converter_base.c final_write.c ft_printf.c initialize_flags.c\
 type_char.c type_dec.c type_oct.c type_str.c type_hex.c type_float.c get_next_line.c

OBJ_LIB = $(addprefix $(LIB_PATH), $(LIB:.c=.o))

OBJ_SRC = $(SRC_NAME:.c=.o)

OBJ = $(OBJ_LIB) $(OBJ_SRC)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\r\033[48;5;15;38;5;25m✅  MADE libft.a \033[0m\033[K"

$(OBJ_LIB): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

$(OBJ_SRC): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

clean:
	@rm -f $(OBJ) ft_printf.h.gch $(LIB_PATH)libft.h.gch get_next_line.h.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all