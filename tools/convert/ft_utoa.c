/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:22:53 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	void	ft_put_utoa(unsigned int n, char *ret)
{
	if ((n / 10) > 0)
	{
		ft_put_utoa(n / 10, ret - 1);
		*ret = (n % 10) + '0';
	}
	else
		*ret = n + '0';
}

char	*ft_utoa(unsigned int n)
{
	char	*ret;
	int		len;

	len = ft_ui_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	*(ret + len) = '\0';
	ft_put_utoa(n, ret + len - 1);
	return (ret);
}
