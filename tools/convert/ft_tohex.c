/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:22:08 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_tohex(size_t n, char *hex)
{
	size_t	tmp;

	tmp = n;
	if (n / 16)
		ft_tohex(n / 16, hex);
	ft_putchar(hex[n % 16]);
	return (ft_hex_len(tmp));
}
