# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 18:05:05 by ntoshihi          #+#    #+#              #
#    Updated: 2020/12/26 04:51:56 by ntoshihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ${shell find ./srcs/*.c}
OBJS	= $(SRCS:.c=.o)
HEADER	= ./includes/ft_printf.h
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
