/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_players_by_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:05:39 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/09 15:05:41 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_after_n_file(char **argv, t_struct *pl)
{
	int		i;
	char	**tmp;

	i = 0;
	while (argv[i])
	{
		if ((ft_strequ(argv[i], "-n") && pl->fl_n > 0))
		{
			i += 2;
			if (argv[i])
			{
				tmp = ft_strsplit(argv[i], '.');
				if (!ft_strequ(tmp[ft_len_db_array(tmp) - 1], "cor"))
					ft_error("after flag '-n' number[1-4] 'file.cor'");
				ft_free_db_array(tmp);
			}
			else
				ft_error("after flag '-n' 'number[1-4]' 'file.cor'");
			i++;
		}
		else
			i++;
	}
}

char 	**move_pl_index(int nb, char *player, char **names)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	j = 0;
	new = NULL;
	while (names[++i])
	{
		if (nb == 0 && j == 0)
		{
			new = ft_add_str_in_double(new, player);
			j = 1;
		}
		if (!ft_strequ(names[i], player))
			new = ft_add_str_in_double(new, names[i]);
		if (i == nb && j == 0)
			new = ft_add_str_in_double(new, player);
	}
	return (new);
}

char 	**ft_move_pl_by_n(char **argv, char **names, t_struct *pl)
{
	int		i;
	int		num_tmp;

	i = 0;
	check_after_n_file(argv, pl);
	while (argv[i])
	{
		if(ft_strequ(argv[i], "-n"))
		{
			num_tmp = argv[++i][0] - '0';
			if (num_tmp - 1 < pl->num_pl)
				names = move_pl_index(num_tmp - 1, argv[++i], names);
			else
				ft_error("input number isn't correct");
		}
		else
			i++;
	}
	return (names);
}
