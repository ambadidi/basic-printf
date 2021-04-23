/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:24:05 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_char(t_flags *flags, char c)
{
	if (flags->minwidth)
		flags->minwidth -= 1;
	if (!flags->minus)
	{
		while (flags->minwidth--)
		{
			if (flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		while (flags->minwidth--)
		{
			if (flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	return (0);
}
