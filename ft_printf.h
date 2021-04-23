/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:20:05 by abadidi           #+#    #+#             */
/*   Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

typedef struct s_flags
{
	int	zero;
	int	point;
	int	minus;
	int	minwidth;
	int	precission;
	int	check;
}				t_flags;
int					g_nbr;
void				set_route(char c, t_flags *flags, va_list list);
int					ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_tohex(size_t n, char *hex);
int					ft_putstr(char *s, t_flags *flags);
void				ft_putchar(char c);
int					ft_printf(const char *s, ...);
int					ft_atoi(const char *str);
char				*ft_utoa(unsigned int n);
int					ft_isdigit(int c);
int					ft_ui_len(unsigned long long n);
int					ft_int_len(int n);
int					ft_hex_len(unsigned long long n);
char				*ft_itoa(long n);
int					ft_p(t_flags *flags, unsigned long long n);
int					ft_u_int(t_flags *flags, unsigned int n);
int					ft_varwidth(t_flags *flags, long long n, int type);
int					ft_p_width(t_flags *flags, unsigned long long n);
int					ft_int(t_flags *flags, int n);
int					ft_smol_hex(t_flags *flags, unsigned long n);
int					ft_big_hex(t_flags *flags, unsigned long n);
int					ft_char(t_flags *flags, char c);
int					ft_string(t_flags *flags, char *s);

#endif
