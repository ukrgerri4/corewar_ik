/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:26:02 by apoplavs          #+#    #+#             */
/*   Updated: 2017/01/19 15:52:11 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		write_line(char **line, t_fd *tmp)
{
	int			i;
	char		*s;

	i = 0;
	while (tmp->str[i] != '\n' && tmp->str[i])
		i++;
	*line = ft_strnew((size_t)i);
	ft_strncpy(*line, tmp->str, (size_t)i);
	if (!tmp->str[i] && i == 0)
		return (0);
	s = ft_strdup(tmp->str + i + 1);
	free(tmp->str);
	tmp->str = s;
	return (1);
}

static char		*ft_read_support(char *p, char *str, char *str1, int m)
{
	if (m == 0)
	{
		if (str != NULL)
			return (ft_strdup(str));
		else
			return (NULL);
	}
	if (m == 1)
	{
		free(str);
		free(str1);
		return (p);
	}
	if (m == 2)
	{
		if (str != NULL)
			free(str);
		str = ft_strdup(p);
		free(p);
		return (str);
	}
	return (0);
}

static int		ft_read_file(int t, t_fd *tmp, char *buf, size_t len)
{
	char		*tab;
	char		*p;

	tab = NULL;
	p = ft_read_support(tab, tmp->str, tmp->str, 0);
	free(tmp->str);
	while (t > 0)
	{
		if ((t = (int)read(tmp->fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (p != NULL && (tab = ft_read_support(p, tab, buf, 2)))
			len = ft_strlen(tab);
		if ((p = ft_strnew((size_t)BUFF_SIZE + len)) == NULL)
			return (-1);
		if (tab != NULL)
			ft_strcpy(p, tab);
		ft_strcat(p, buf);
		if ((ft_strchr(buf, '\n') != NULL) || (ft_strlen(buf) < BUFF_SIZE))
			break ;
		ft_bzero(buf, (size_t)BUFF_SIZE);
	}
	tmp->str = ft_read_support(p, buf, tab, 1);
	return (t);
}

static t_fd		*ft_serch(t_fd **src, int fd)
{
	t_fd		*find;

	find = *src;
	while (find)
	{
		if (find->fd == fd)
			return (find);
		find = find->next;
	}
	find = (t_fd*)malloc(sizeof(t_fd));
	find->fd = fd;
	find->str = NULL;
	find->next = *src;
	*src = find;
	return (find);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd	*tmp;
	t_fd		*p;
	int			t;
	char		*buf;
	char		s[1];

	if (BUFF_SIZE < 1 || fd < 0 || read(fd, s, 0) == -1)
		return (-1);
	*line = NULL;
	t = 0;
	p = ft_serch(&tmp, fd);
	if (p->str != NULL && ft_strchr(p->str, '\n') != NULL
		&& write_line(line, p))
		return (1);
	if ((buf = ft_strnew((size_t)BUFF_SIZE)) == NULL)
		return (-1);
	t = ft_read_file(1, p, buf, 0);
	if (t == -1 || (write_line(line, p) == 0 && t == 0))
	{
		ft_bzero(*line, ft_strlen(*line));
		free(tmp->str);
		free(tmp);
		return (t);
	}
	return (1);
}
