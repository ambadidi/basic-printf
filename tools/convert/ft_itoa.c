/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:21:47 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	int	len(long n)
{
	int	l;

	if (n >= 0)
		l = 0;
	else
		l = 1;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static	void	ft_put_itoa(long n, char *ret)
{
	if ((n / 10) > 0)
	{
		ft_put_itoa(n / 10, ret - 1);
		*ret = (n % 10) + '0';
	}
	else
		*ret = n + '0';
}

char	*ft_itoa(long n)
{
	char	*ret;

	if (n == -2147483648)
	{
		ret = (char *)malloc(sizeof(char) * 12);
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, "2147483648", 12);
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!ret)
		return (NULL);
	*(ret + len(n)) = '\0';
	if (n < 0)
	{
		*ret = '-';
		n *= -1;
		ft_put_itoa(n, ret + len(n));
	}
	else
		ft_put_itoa(n, ret + len(n) - 1);
	return (ret);
}
