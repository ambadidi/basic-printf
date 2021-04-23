/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:25:21 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:30:15 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	normal_ui(t_flags *flags, unsigned int n, int width)
{
	while ((width >= 0) && width--)
		if (flags->zero && !flags->point
			&& (flags->precission || flags->minwidth))
			ft_putchar('0');
	else
		 ft_putchar(' ');
	if (n == 0 && flags->precission != 0)
	{
		flags->point += 1;
		flags->precission += 1;
	}
	while (flags->point && flags->precission--)
		ft_putchar('0');
	if (!(flags->point == 2 && n == 0))
		if (ft_putstr(ft_utoa(n), flags) == -1)
			return (-1);
	return (0);
}

static int	minus_ui(t_flags *flags, unsigned int n, int width)
{
	if (n == 0 && flags->precission != 0)
	{
		flags->point += 1;
		flags->precission += 1;
	}
	while (flags->point && flags->precission--)
		ft_putchar('0');
	if (!(flags->point == 2 && n == 0))
		if (ft_putstr(ft_itoa(n), flags) == -1)
			return (-1);
	while ((width >= 0) && width--)
		if (flags->zero && !flags->point
			&& (flags->precission || flags->minwidth))
			ft_putchar('0');
	else
		 ft_putchar(' ');
	return (0);
}

int	ft_u_int(t_flags *flags, unsigned int n)
{
	int	width;

	width = 0;
	if (flags->minwidth)
		width = ft_varwidth(flags, n, 0);
	if (ft_ui_len(n) >= flags->precission && n != 0)
		flags->precission = 0;
	else
		flags->precission -= ft_ui_len(n);
	if ((!flags->minus || flags->zero))
		return (normal_ui(flags, n, width));
	return (minus_ui(flags, n, width));
}
