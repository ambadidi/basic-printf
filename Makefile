# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadidi <abadidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 00:19:42 by abadidi           #+#    #+#              #
#    Updated: 2021/04/23 00:28:45 by abadidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS =	ft_printf.c					\
		tools/ft_router.c					\
		tools/ft_atoi.c				\
		tools/ft_print_p.c			\
		tools/ft_print_x.c			\
		tools/convert/ft_itoa.c		\
		tools/ft_isdigit.c			\
		tools/ft_print_s.c			\
		tools/ft_str/ft_putchar.c	\
		tools/convert/ft_tohex.c	\
		tools/ft_print_c.c			\
		tools/ft_print_smol_x.c		\
		tools/ft_str/ft_putstr.c	\
		tools/convert/ft_utoa.c		\
		tools/ft_print_i.c			\
		tools/ft_print_ui.c			\
		tools/ft_varwidth.c
		
OBJ =	ft_printf.o					\
		ft_atoi.o					\
		ft_print_p.o				\
		ft_router.o					\
		ft_print_x.o				\
		ft_itoa.o					\
		ft_isdigit.o				\
		ft_print_s.o				\
		ft_putchar.o				\
		ft_tohex.o					\
		ft_print_c.o				\
		ft_print_smol_x.o			\
		ft_putstr.o					\
		ft_utoa.o					\
		ft_print_i.o				\
		ft_print_ui.o				\
		ft_varwidth.o
		
$(NAME):
	clang $(FLAGS) $(SRCS)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all

bonus: fclean
	gcc $(FLAGS) $(SRCS) $(BONUS)
	ar -rc $(NAME) $(SRCS:.o=.o)
	ranlib $(NAME)