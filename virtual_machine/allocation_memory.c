/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:00:55 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/22 16:01:22 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

char		**ft_add_str_in_double(char **old, char *str)
{
	int		j;
	char	**tmp;

	j = 0;
	if (!old)
	{
		tmp = (char **)malloc(sizeof(tmp) * 2);
		tmp[0] = ft_strdup(str);
		tmp[1] = NULL;
		old = tmp;
	}
	else
	{
		while (old[j])
			j++;
		tmp = (char **)malloc(sizeof(tmp) * (j + 2));
		j = -1;
		while (old[++j])
			tmp[j] = ft_strdup(old[j]);
		tmp[j] = ft_strdup(str);
		tmp[j + 1] = NULL;
		ft_free_db_array(old);
		old = tmp;
	}
	return (old);
}