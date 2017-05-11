/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:48:11 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/02 17:48:13 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_c(unsigned char c, t_flags *flag, int n)
{
	unsigned char	*s;
	unsigned char	cm;

	cm = flag->zero == TRUE ? '0' : ' ';
	s = (unsigned char *)ft_strnew(2);
	if (c == '\0')
	{
		c--;
		n = -1;
	}
	s[0] = c;
	if (flag->width > 1)
		s = filwidth_c(flag, s, cm);
	if (n == -1)
		while (s[++n])
		{
			ft_putchar(s[n] == c ? '\0' : s[n]);
			flag->len++;
		}
	else
		final_write((char *)s, flag);
}

void				type_c(va_list *arg, t_flags *flag, unsigned char in)
{
	unsigned char	c;

	c = in == 0 ? (unsigned char)va_arg(*arg, int) : in;
	write_c(c, flag, 1);
}

void				type_lc(va_list *arg, t_flags *flag)
{
	char			*wchar;
	int				wch;

	wch = va_arg(*arg, int);
	if (wch == 0)
		write_c((unsigned char)wch, flag, 1);
	else
	{
		wchar = convert_wchar(wch);
		write_s(wchar, flag, (int)ft_strlen(wchar));
		free(wchar);
	}
}

char				*convert_wchar(int i)
{
	unsigned char	*res;

	res = (unsigned char *)ft_strnew(3);
	if (i < 128)
		*res = i;
	else if (i < 2048)
	{
		res[0] = (i >> 6) + 192;
		res[1] = i << 2;
		res[1] = (res[1] >> 2) + 128;
	}
	else if (i > 2048)
	{
		res[0] = (i >> 12) + 224;
		res[1] = i >> 6;
		res[1] = res[1] << 2;
		res[1] = res[1] >> 2;
		res[1] += 128;
		res[2] = i << 2;
		res[2] = (res[2] >> 2) + 128;
	}
	return ((char *)res);
}

unsigned char		*filwidth_c(t_flags *flag, unsigned char *s,
	unsigned char c)
{
	unsigned char	*p;

	p = s;
	s = (unsigned char *)ft_strnew(flag->width + 1);
	if (flag->hyphen == TRUE)
	{
		ft_strcpy((char *)s, (char *)p);
		ft_memset(s + ft_strlen((char *)p), c,
			flag->width - ft_strlen((char *)p));
	}
	else
	{
		ft_memset(s, c, flag->width - ft_strlen((char *)p));
		ft_strcat((char *)s, (char *)p);
	}
	free(p);
	return (s);
}
