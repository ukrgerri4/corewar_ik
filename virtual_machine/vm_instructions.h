#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

# include "vm.h"

typedef struct      s_fun_arg
{
    int 			args[3];
    unsigned char 	**type_and_len;
    unsigned char	*start_point;
}                   t_fun_arg;

/*
** instruction_help_0.c, instruction_help_1.c
*/
void                init_fun_arg(t_fun_arg *arg);
int		            input_params(unsigned char **type_and_len, int *args, t_struct *data, t_pc *p);
int 		        ft_check_arguments(unsigned char *arg, int n);
void                ft_choose_arg(unsigned char **p, unsigned char **type_and_len, int n);
int		            exit_with_move(t_struct *data, unsigned char **type_and_len, t_pc *p, int i);
unsigned int	    get_argument(t_struct *data, unsigned char **p, int size);
void                set_arguments(t_struct *data, unsigned int reg, unsigned char *p, int color);
void                change_carry(t_pc *p, unsigned int value);
void	            get_last_value(t_struct *data, t_fun_arg *arg, int nb, t_pc *p);
void                get_last_long_value(t_struct *data, t_fun_arg *arg, int nb, t_pc *p);

/*
** functions
*/
int		            live(t_struct *data, t_pc *p);
int 	            ld(t_struct *data, t_pc *p);
int		            st(t_struct *data, t_pc *p);
int 		        add(t_struct *data, t_pc *p);
int 		        sub(t_struct *data, t_pc *p);
int			        and(t_struct *data, t_pc *p);
int			        or(t_struct *data, t_pc *p);
int			        xor(t_struct *data, t_pc *p);
int 		        zjmp(t_struct *data, t_pc *p);
int 		        sti(t_struct *data, t_pc *p);
int 	            ldi(t_struct *data, t_pc *p);
int 		        my_fork(t_struct *data, t_pc *p);
int 		        lld(t_struct *data, t_pc *p);
int 	            lldi(t_struct *data, t_pc *p);
int 	            lfork(t_struct *data, t_pc *p);
int 	            aff(t_struct *data, t_pc *p);

#endif
