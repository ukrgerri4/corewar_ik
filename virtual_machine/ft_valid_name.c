/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:46:43 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/22 15:46:48 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	ft_create_players(char **names, t_struct *pl)
{
	int i;

	i = 0;
	if (!names)
		ft_error("no players");
	pl->players	= (t_st **)malloc(sizeof(pl->players) * (pl->num_pl + 1));
	pl->players[pl->num_pl] = NULL;
//	while (names && names[i])
	while (names && i < pl->num_pl)
	{
		pl->players[i] = (t_st *)malloc(sizeof(t_st));
		pl->players[i]->file_name = ft_strdup(names[i]);
//		pl->players[i]->name = NULL;
//		pl->players[i]->comment = NULL;
//		pl->players[i]->code = NULL;
//		pl->players[i]->size_cd = 0;
		i++;
	}

}

int		ft_len_db_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void 	ft_valid_name(char **argv, t_struct *pl)
{
	int		i;
	char 	**names;
	char	**tmp;

	i = 1;
	names = NULL;
	while (argv[i])
	{
		tmp = ft_strsplit(argv[i], '.');
//		ft_printf("1 -[%s] 2 -[%s]\n", tmp[0], tmp[1]);
		if (ft_len_db_array(tmp) == 2 && ft_strequ(tmp[1], "cor"))
		{
			names = ft_add_str_in_double(names, argv[i]);
			pl->num_pl++;
		}
		else if (!ft_strequ(tmp[0], "-n") && !ft_strequ(tmp[0], "-d"))
			ft_error("bad argument input");
		else if (ft_strequ(tmp[0], "-d") && pl->fl_dump > 0)
			i++;
		ft_free_db_array(tmp);
		i++;
	}
	if (pl->num_pl > 4)
		ft_error("to many bots");
	ft_create_players(names, pl);
	ft_free_db_array(names);
}