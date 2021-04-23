/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:24:59 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	normal_s(t_flags *flags, char *s, int width)
{
	if (g_nbr == -1)
		return ;
	while ((width >= 0) && width--)
		ft_putchar(' ');
	g_nbr += write(1, s, flags->precission);
}

static void	minus_s(t_flags *flags, char *s, int width)
{
	g_nbr += write(1, s, flags->precission);
	while ((width >= 0) && width--)
		ft_putchar(' ');
}

int	ft_string(t_flags *flags, char *s)
{
	int		width;

	width = 0;
	if (!s)
		s = "(null)";
	if ((flags->point && (flags->precission > ft_strlen(s))) || !flags->point)
		flags->precission = ft_strlen(s);
	if (flags->minwidth)
	{
		if (flags->minwidth < flags->precission)
			width = 0;
		else
			width = flags->minwidth - flags->precission;
	}
	if ((!flags->minus))
		normal_s(flags, s, width);
	else
		minus_s(flags, s, width);
	return (0);
}
