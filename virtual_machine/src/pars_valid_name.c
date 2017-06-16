/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:46:43 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/15 20:41:47 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_create_players(char **argv, char **names, t_struct *pl)
{
	int i;

	i = 0;
	if (!names)
		ft_error("no players");
	names = ft_move_pl_by_n(argv, names, pl);
	pl->players = (t_st **)malloc(sizeof(pl->players) * (pl->num_pl + 1));
	pl->players[pl->num_pl] = NULL;
	while (names && i < pl->num_pl)
	{
		pl->players[i] = (t_st *)malloc(sizeof(t_st));
		pl->players[i]->file_name = ft_strdup(names[i]);
		pl->players[i]->player_number = (unsigned int)((i + 1) * -1);
		pl->number_last_live_player = pl->players[i]->player_number;
		init_pc(pl, pl->map + i * (MEM_SIZE / pl->num_pl), i);
		pl->first->r[1] = pl->players[i]->player_number;
		pl->players[i]->count_live = 0;
		i++;
	}
}

int		len_arr(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_valid_name(char **argv, t_struct *pl, int i)
{
	char	**names;
	char	**tmp;

	names = NULL;
	while (argv[++i])
	{
		tmp = ft_strsplit(argv[i], '.');
		if (len_arr(tmp) >= 2 && ft_strequ(tmp[len_arr(tmp) - 1], "cor"))
		{
			names = ft_add_str_in_double(names, argv[i]);
			pl->num_pl++;
		}
		else if (!ft_strequ(tmp[0], "-n") &&
				!ft_strequ(tmp[0], "-d") && !ft_strequ(tmp[0], "-v"))
			ft_error("bad argument input");
		else if ((ft_strequ(tmp[0], "-d") && pl->fl_dump > 0)
				|| (ft_strequ(tmp[0], "-n") && pl->fl_n > 0))
			i++;
		ft_free_db_array(tmp);
	}
	if (pl->num_pl > 4)
		ft_error("to many bots");
	ft_create_players(argv, names, pl);
	ft_free_db_array(names);
}
