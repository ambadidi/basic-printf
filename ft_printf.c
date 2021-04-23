/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:20:24 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->point = 0;
	flags->zero = 0;
	flags->minwidth = 0;
	flags->precission = 0;
	flags->check = 0;
}

void	help_flags(const char **s, va_list list, t_flags *flags)
{
	if (**s == '.')
	{
		flags->point = 1;
		(*s)++;
		if (ft_isdigit(**s))
		{
			flags->precission = ft_atoi(++*s);
			while (ft_isdigit(**s))
				*s += 1;
		}
		else if (**s == '*')
		{
			(*s)++;
			flags->precission = va_arg(list, int);
			if (flags->precission < 0)
				flags->precission = 0;
		}
	}
	if (flags->minwidth < 0)
	{
		flags->minwidth *= -1;
		flags->minus = 1;
		flags->zero = 0;
	}
}

void	help_flags2(const char **s, t_flags *flags)
{
	while (**s == '0' || **s == '-')
	{
		if (**s == '0')
			flags->zero = 1;
		else
			flags->minus = 1;
		(*s)++;
	}
}

static int	get_flags(const char **s, va_list list)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	init_flags(flags);
	help_flags2(s, flags);
	if (**s == '*')
	{
		(*s)++;
		flags->minwidth = va_arg(list, int);
	}
	else if (ft_isdigit(**s))
	{
		flags->minwidth = ft_atoi(*s);
		while (ft_isdigit(**s))
			*s += 1;
	}
	help_flags(s, list, flags);
	set_route(**s++, flags, list);
	free(flags);
	return (g_nbr);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;

	g_nbr = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (get_flags(&s, list) < 0)
				return (-1);
		}
		else
			ft_putchar(*s);
		s++;
	}
	va_end(list);
	return (g_nbr);
}
