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

# include "../libftprintf/get_next_line.h"
# include "../op.h"
# include <errno.h>
# include <ncurses.h>

typedef struct      s_op
{
    char            *name;
    int             nb_param;
    char            params_types[3];
    int             opcode;
    int             nb_tours;
    char            *full_name;
    char            params_byte;
    char            index_size;
}                   t_op;

t_op                *g_tab;

typedef struct	s_pc
{
	unsigned int 	r[17];
    int             owner;
	int 			live;
	int				cycles;
	int 			carry;
	unsigned char	cur_fun;
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
	int				num_pl;
	int				fl_dump;
	int 			fl_n;
    int 			fl_v;
	t_st			**players;

	unsigned char 	*map;
    unsigned char   *color;
    unsigned int    number_last_live_player;
    int             glob_cycles;
    int             nbr_live;
    int             max_checks;
    t_pc			*first;
    t_pc			*last;

	int 			current_cycle;
    useconds_t      speed;
}				t_struct;

typedef struct	s_out
{
	WINDOW *map;
	WINDOW *info1;
	WINDOW *info2;
	WINDOW *info3;
}				t_out;

int             (*g_fun[17])(t_struct *pl, t_pc *current_pc);
t_out			out;

# include "vm_instructions.h"

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
** ft_move_players_by_n
*/
char 	**ft_move_pl_by_n(char **argv, char **names, t_struct *pl);

/*
**alloc_and_free_memory.c
*/
char	**ft_add_str_in_double(char **old, char *str);
void	ft_free_db_array(char **array);

/*
** base_function
*/
void	ft_fill_int(unsigned int *arr, int size, unsigned int n);
void	ft_bchar(unsigned char *arr, int size, unsigned char c);
void    move_ptr(t_struct *pl, unsigned char **ptr, int i);
void 	ft_error(char *error);

/*
** init_function
*/
t_op 	*init_tab(void);
void 	ft_init_st(t_struct	*pl);
void	init_pc(t_struct *pl, unsigned char *ptr, int i);
void    delete_pc(t_struct *pl, t_pc **del);
void    init_function(void);

/*
** exec_pc
*/
void    start_vm(t_struct *pl);
int     set_cycles(t_pc *cur);
void    set_del(void);
void    move_pc(t_struct *pl);
void    kill_or_save_pc(t_struct *pl);

/*
** visualization
*/
void 	init_window(t_struct *pl);
void    set_frame(void);
void    out_map(t_struct *pl);
void    out_info1(t_struct *pl);
void    out_info2(t_struct *pl); //debug version
void    out_info3(t_struct *pl);
void    out_dump(t_struct *pl);
void    out_start_position(t_struct *pl);
void    out_winner(t_struct *pl);
void    set_color(t_struct *pl, unsigned char *ptr, int color);

#endif
