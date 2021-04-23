/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:25:38 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:30:15 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_route(char c, t_flags *flags, va_list list)
{
	int	ret;

	ret = 0;
	if (c == 'd' || c == 'i')
		ret = ft_int(flags, va_arg(list, int));
	else if (c == 'u')
		ret = ft_u_int(flags, va_arg(list, unsigned int));
	else if (c == 'p')
		ret = ft_p(flags, (unsigned long long)va_arg(list, void *));
	else if (c == 'x')
		ret = ft_smol_hex(flags, va_arg(list, unsigned int));
	else if (c == 'X')
		ret = ft_big_hex(flags, va_arg(list, unsigned int));
	else if (c == 'c')
		ret = ft_char(flags, va_arg(list, int));
	else if (c == '%')
		ret = ft_char(flags, '%');
	else if (c == 's')
		ret = ft_string(flags, va_arg(list, char *));
	(ret == -1) && (g_nbr = -1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
