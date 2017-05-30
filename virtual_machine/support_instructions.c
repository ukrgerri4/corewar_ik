
#include "virtual_machine.h"

unsigned int	get_argument(t_struct *data, t_pc *p, int size) // зчитує аргументи для команди
{
	unsigned int args;
	int 		i;

	args = 0;
	i = 0;
	move_ptr(data, &p->pc_ptr, 1);
	while (i < size)
	{
		args = args << 8;
		args |= *p->pc_ptr;//args |= function from igor move ptn;
		move_ptr(data, &p->pc_ptr, 1);
		i++;
	}
	return (args);
}
