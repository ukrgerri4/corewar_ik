/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:56:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/30 17:56:04 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

# include "virtual_machine.h"

/*
**checking_instructions.c
*/
int		ft_choose_arg(t_struct *data, unsigned char **p, unsigned char *args, int n);
void	get_len_write(unsigned char *args, unsigned char *args_len, int len_dir);
long int	cast_if_negative(long int arg);
long int	cast_if_negative_int(long int arg);


/*
**instruction_live.c
*/
int		live(t_struct *data, t_pc *p);
/*
**instruction_ld.c
*/
int 	ld(t_struct *data, t_pc *p);

/*
**instruction_st.c
*/
int		st(t_struct *data, t_pc *p);

/*
**instruction_add.c
*/
int 		add(t_struct *data, t_pc *p);

/*
**instruction_sub.c
*/
int 		sub(t_struct *data, t_pc *p);

/*
**instruction_lld.c
*/
int 		lld(t_struct *data, t_pc *p);
/*
**instruction_and.c
*/
void		ft_for_and_or_xor(t_struct *data, t_pc *p, long int **arg, unsigned char *args);
int			and(t_struct *data, t_pc *p);

/*
**instruction_or.c
*/
int			or(t_struct *data, t_pc *p);

/*
**instruction_xor.c
*/
int			xor(t_struct *data, t_pc *p);

/*
**instruction_sti.c
*/

int 		sti(t_struct *data, t_pc *p);

/*
**instruction_zjmp.c
*/

int 		zjmp(t_struct *data, t_pc *p);
/*
**instruction_ldi.c
*/
int 	    ldi(t_struct *data, t_pc *p);

/*
**instruction_fork.c
*/
void	create_pc_fork_lfork(t_struct *data, t_pc *p, unsigned char *point);
int 		my_fork(t_struct *data, t_pc *p);
/*
**instruction_lldi.c
*/
int 	lldi(t_struct *data, t_pc *p);


int 	lfork(t_struct *data, t_pc *p);

int 	aff(t_struct *data, t_pc *p);
/*
**support_instructions.c
*/
void			get_len_write(unsigned char *args, unsigned char *args_len, int len_dir);
unsigned int	get_argument(t_struct *data, unsigned char **p, int size);
void            change_carry(t_pc *list, unsigned int value);
void            set_arguments(t_struct *data, unsigned int reg, unsigned char *p, int color);
/*
**input_params.c
*/
unsigned char	**init_type_len(void);
void	get_indirect_value(unsigned char *point, int *args, t_struct *data);
int		input_params(unsigned char **type_and_len, int *args, t_struct *data, t_pc *p); // зчитує аргументи для команди

#endif //COREVAR_INSTRUCTIONS_H
