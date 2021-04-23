/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:24:44 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	normal_p(t_flags *flags, unsigned long long n, int width)
{
	while ((width >= 0) && width--)
		ft_putchar(' ');
	ft_putstr("0x", flags);
	if (!(flags->point && n == 0))
		ft_tohex(n, "0123456789abcdef");
	return (0);
}

static	int	minus_p(t_flags *flags, unsigned long long n, int width)
{
	ft_putstr("0x", flags);
	if (!(flags->point && n == 0))
		ft_tohex(n, "0123456789abcdef");
	while ((width >= 0) && width--)
		ft_putchar(' ');
	return (0);
}

int	ft_p(t_flags *flags, unsigned long long n)
{
	flags->minwidth -= ft_hex_len(n);
	if (flags->point && n == 0)
		flags->minwidth -= 1;
	else
		flags->minwidth -= 2;
	if (!flags->minus)
		return (normal_p(flags, n, flags->minwidth));
	return (minus_p(flags, n, flags->minwidth));
}
