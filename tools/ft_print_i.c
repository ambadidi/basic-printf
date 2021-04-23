/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:24:21 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	normal(t_flags *flags, int n, int width, long nbr)
{
	while ((width >= 0) && width--)
	{
		if (flags->zero && !flags->point && (flags->precission
				|| flags->minwidth))
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if ((nbr < 0) && flags->check)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (n == 0 && flags->precission != 0)
		flags->precission++;
	while (flags->point && flags->precission--)
		ft_putchar('0');
	if (!(flags->point == 2 && n == 0))
	{
		if ((n < 0 && flags->zero) || (nbr > 0 && n < 0))
			ft_putstr(ft_itoa(-n), flags);
		else
			ft_putstr(ft_itoa(n), flags);
	}
	return (0);
}

static int	minus(t_flags *flags, int n, int width, long nbr)
{
	if ((nbr < 0) && flags->check)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (n == 0 && flags->precission != 0)
		flags->precission++;
	while (flags->point && flags->precission--)
		ft_putchar('0');
	if (!(flags->point == 2 && n == 0))
	{
		if ((n < 0 && flags->zero) || (nbr > 0 && n < 0))
			ft_putstr(ft_itoa(-n), flags);
		else
			ft_putstr(ft_itoa(n), flags);
	}
	while ((width >= 0) && width--)
	{
		if (flags->zero && !flags->point && (flags->precission
				|| flags->minwidth))
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (0);
}

int	ft_int(t_flags *flags, int n)
{
	int		width;
	long	nbr;

	width = 0;
	nbr = n;
	if (flags->minwidth)
		width = ft_varwidth(flags, n, 0);
	if (n < 0)
		if ((ft_int_len(n) == flags->precission)
			&& flags->minwidth > flags->precission)
			width--;
	if (ft_int_len(n) >= flags->precission && n != 0)
		flags->precission = 0;
	else
		(flags->precission -= ft_int_len(n));
	if (n < 0 && flags->zero && !flags->point)
		ft_putchar('-');
	else
		flags->check = 1;
	if ((!flags->minus || flags->zero))
		return (normal(flags, n, width, nbr));
	return (minus(flags, n, width, nbr));
}
