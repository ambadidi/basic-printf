/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:25:50 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:30:33 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_int_len(int n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_hex_len(unsigned long long n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		n /= 16;
		l++;
	}
	return (l);
}

int	ft_ui_len(unsigned long long n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static	int	ft_varwidth_next(t_flags *flags, int len, long long n)
{
	if (n == 0 && flags->point)
		len = 0;
	if (flags->precission < len)
		flags->precission = 0;
	if (flags->minwidth && flags->precission)
	{
		if (n < 0 && (flags->precission > len))
			flags->minwidth--;
		if (flags->minwidth - flags->precission < 0)
			return (0);
		else
			return (flags->minwidth - flags->precission);
	}
	else
	{
		if (n < 0)
			return (flags->minwidth - len - 1);
		else
			return (flags->minwidth - len);
	}
	return (0);
}

int	ft_varwidth(t_flags *flags, long long n, int type)
{
	int	len;

	if (type)
		len = ft_hex_len(n);
	else if (n > 0)
		len = ft_ui_len(n);
	else
		len = ft_int_len(n);
	return (ft_varwidth_next(flags, len, n));
}
