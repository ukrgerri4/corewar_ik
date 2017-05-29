/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:37:50 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/22 13:37:53 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include "../asm/asm.h"
# include "../libftprintf/get_next_line.h"
# include "../op.h"
# include <stdio.h>
# include <errno.h>
# include <ncurses.h>

typedef struct	s_pc
{
	unsigned int 	r[17];
	int 			live;
	int				cycles;
	int 			carry;
	unsigned char	*pc_ptr;
	struct s_pc		*next;
    struct s_pc		*prev;
}				t_pc;


typedef struct	s_st
{
	char				*file_name;
	unsigned char		*magic;
	unsigned char		*name;
	int					size_cd;
	unsigned char		*comment;
	unsigned char 		*code;

	unsigned int 		player_number;
    int                 count_live;
}				t_st;

typedef struct	s_struct
{
	int				num_pl;//колтчевство игроков
	int				fl_dump;//if (-1, nothing) else (num where must stop)
	int 			fl_n;//visualisation flag "-n"
	t_st			**players;

	unsigned char 	*map;
    unsigned int    number_last_live_player;
    int             nbr_live;
    int             max_checks;
    int             glob_cycles;
	int 			iterator;//delete
    t_pc			*first;
    t_pc			*last;
}				t_struct;

//if exist flag "-n", flag -dump will be ignored

/*
**main.c
*/
int		main(int argv, char **argc);

/*
**ft_parsing_file.c
*/
void	ft_parsing_file(t_struct *pl);
int 	ft_interpretation(unsigned char *str, int size);

/*
**ft_search_flags.c
*/
void 	ft_search_flags(char **argc, int argv, t_struct	*pl);

/*
**valid_name.c
*/
void 	ft_valid_name(char **argv, t_struct *pl);
int		ft_len_db_array(char **array);

/*
**allocation_memory.c
*/
char		**ft_add_str_in_double(char **old, char *str);

/*
**free_memory.c
*/
void	ft_free_db_array(char **array);

/*
**ft_error.c
*/
void 	ft_error(char *error);

/*
** ik_function
*/
void	ft_fill_int(unsigned int *arr, int size, unsigned int n);
void    init_pc(t_struct *pl, unsigned char *ptr);
void    delete_pc(t_struct *pl, t_pc **del);

void    start_vm(t_struct *pl);
void    move_ptr(t_struct *pl, unsigned char **ptr, int i);

void 	init_window(void);
void	visualization(t_struct *pl, size_t size);

#endif
