/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:35:20 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 20:39:24 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libftprintf/get_next_line.h"
# include "../op.h"
# include <errno.h>
# include <ncurses.h>

typedef struct		s_op
{
	char			*name;
	int				nb_param;
	char			params_types[3];
	int				opcode;
	int				nb_tours;
	char			*full_name;
	char			params_byte;
	char			index_size;
}					t_op;

typedef struct		s_pc
{
	unsigned int	r[17];
	int				owner;
	int				live;
	int				cycles;
	int				carry;
	unsigned char	cur_fun;
	unsigned char	*pc_ptr;
	struct s_pc		*next;
	struct s_pc		*prev;
}					t_pc;

typedef struct		s_st
{
	char			*file_name;
	unsigned char	*magic;
	unsigned char	*name;
	int				size_cd;
	unsigned char	*comment;
	unsigned char	*code;
	unsigned int	player_number;
	int				count_live;
}					t_st;

typedef struct		s_struct
{
	int				num_pl;
	int				fl_dump;
	int				fl_n;
	int				fl_v;
	t_st			**players;
	unsigned char	*map;
	unsigned char	*color;
	unsigned int	number_last_live_player;
	int				glob_cycles;
	int				nbr_live;
	int				max_checks;
	t_pc			*first;
	t_pc			*last;
	int				current_cycle;
	useconds_t		speed;
}					t_struct;

typedef struct		s_fun_arg
{
	int				args[3];
	unsigned char	**type_and_len;
	unsigned char	*start_point;
}					t_fun_arg;

typedef struct		s_out
{
	WINDOW			*map;
	WINDOW			*info1;
	WINDOW			*info2;
	WINDOW			*info3;
}					t_out;

t_op				g_tab[17];
int					(*g_fun[17])(t_struct *pl, t_pc *current_pc);
t_out				g_out;

/*
** parsing_file
*/
void				ft_parsing_file(t_struct *pl);
int					ft_interpretation(unsigned char *str, int size);
void				ft_search_flags(char **argc, int argv, t_struct	*pl);
void				ft_valid_name(char **argv, t_struct *pl, int i);
int					len_arr(char **array);
char				**ft_move_pl_by_n(char **argv, char **names, t_struct *pl);

/*
** alloc_and_free
*/
char				**ft_add_str_in_double(char **old, char *str);
void				ft_free_db_array(char **array);

/*
** base_function
*/
void				ft_fill_int(unsigned int *arr, int size, unsigned int n);
void				ft_bchar(unsigned char *arr, int size, unsigned char c);
void				move_ptr(t_struct *pl, unsigned char **ptr, int i);
void				ft_error(char *error);

/*
** init_function
*/
t_op				*init_tab(void);
void				ft_init_st(t_struct	*pl);
void				init_pc(t_struct *pl, unsigned char *ptr, int i);
void				delete_pc(t_struct *pl, t_pc **del);
void				init_function(void);

/*
** exec_pc
*/
void				start_vm(t_struct *pl);
int					set_cycles(t_pc *cur);
void				set_del(void);
void				move_pc(t_struct *pl);
void				kill_or_save_pc(t_struct *pl);

/*
** instruction_help_0.c, instruction_help_1.c
*/
void				init_fun_arg(t_fun_arg *arg);
int					input_params(unsigned char **type_and_len, int *args,
		t_struct *data, t_pc *p);
int					ft_check_arguments(unsigned char *arg, int n);
void				ft_choose_arg(unsigned char **p,
		unsigned char **type_and_len, int n);
int					exit_with_move(t_struct *data,
		unsigned char **type_and_len, t_pc *p, int i);
unsigned int		get_argument(t_struct *data,
		unsigned char **p, int size);
void				set_arguments(t_struct *data,
		unsigned int reg, unsigned char *p, int color);
void				change_carry(t_pc *p, unsigned int value);
void				get_last_value(t_struct *data,
		t_fun_arg *arg, int nb, t_pc *p);
void				get_last_long_value(t_struct *data,
		t_fun_arg *arg, int nb, t_pc *p);

/*
** functions
*/
int					live(t_struct *data, t_pc *p);
int					ld(t_struct *data, t_pc *p);
int					st(t_struct *data, t_pc *p);
int					add(t_struct *data, t_pc *p);
int					sub(t_struct *data, t_pc *p);
int					and(t_struct *data, t_pc *p);
int					or(t_struct *data, t_pc *p);
int					xor(t_struct *data, t_pc *p);
int					zjmp(t_struct *data, t_pc *p);
int					sti(t_struct *data, t_pc *p);
int					ldi(t_struct *data, t_pc *p);
int					my_fork(t_struct *data, t_pc *p);
int					lld(t_struct *data, t_pc *p);
int					lldi(t_struct *data, t_pc *p);
int					lfork(t_struct *data, t_pc *p);
int					aff(t_struct *data, t_pc *p);

/*
** visualization
*/
void				init_window(t_struct *pl);
void				set_frame(void);
void				out_map(t_struct *pl);
void				out_info1(t_struct *pl);
void				out_info2(t_struct *pl);
void				out_info3(t_struct *pl);
void				out_dump(t_struct *pl);
void				out_start_position(t_struct *pl);
void				out_winner(t_struct *pl);
void				set_color(t_struct *pl, unsigned char *ptr, int color);

#endif
