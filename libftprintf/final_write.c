/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:46:48 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/08 15:47:09 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_end_spec(char f)
{
	if (f && f != 's' && f != 'S' && f != 'p' && f != 'd' && f != 'D'
		&& f != 'i' && f != 'o' && f != 'O' && f != 'u' && f != 'U'
		&& f != 'x' && f != 'X' && f != 'c' && f != 'C' && f != 'b'
		&& f != 'n' && f != 'f' && f != 'F' && f != 'm')
		return (1);
	else
		return (0);
}

int			valide_flags(const char *fmt, int i)
{
	while (ft_is_end_spec(fmt[i]))
	{
		if (fmt[i] == '#' || fmt[i] == '0' || fmt[i] == '-' || fmt[i] == '+'
			|| fmt[i] == ' ' || fmt[i] == '*' || fmt[i] == '.' || fmt[i] == 'h'
			|| fmt[i] == 'l' || fmt[i] == 'j' || fmt[i] == 'z' ||
			(fmt[i] >= '0' && fmt[i] <= '9'))
			i++;
		else
			return (i);
	}
	return (-1);
}

char		*main_write(char *str, t_flags *flag, int len)
{
	char	*s;
	char	c;

	c = ' ';
	if (flag->zero == TRUE && flag->precision == FALSE && flag->hyphen == FALSE)
		c = '0';
	s = ft_strdup(str);
	if (flag->precision > len)
	{
		free(s);
		s = ft_strnew(flag->precision + 1);
		ft_memset(s, 48, flag->precision - len);
		ft_strncat(s, str, flag->precision);
	}
	if (flag->width > (int)ft_strlen(s) && flag->width != FALSE)
		s = ft_filwidth(flag, s, c);
	free(str);
	return (s);
}

char		*ft_filwidth(t_flags *flag, char *s, char c)
{
	char	*p;

	p = s;
	s = ft_strnew(flag->width + 1);
	if (flag->hyphen == TRUE)
	{
		ft_strcpy(s, p);
		ft_memset(s + ft_strlen(p), c, flag->width - ft_strlen(p));
	}
	else
	{
		ft_memset(s, c, flag->width - ft_strlen(p));
		ft_strcat(s, p);
	}
	free(p);
	return (s);
}

void		final_write(char *str, t_flags *flag)
{
	ft_putstr(str);
	flag->len += ft_strlen(str);
	free(str);
}
