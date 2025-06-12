# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 14:37:50 by knemcova          #+#    #+#              #
#    Updated: 2024/12/25 14:49:28 by knemcova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror

#r: Add or replace .o files in the archive.
#c: Create the archive if it doesn’t already exist.
#s: Create an index of symbols to speed up linking.
ARS = ar rcs

SRCS = ft_printf.c characters.c numbers.c 
OBJS = $(SRCS:.c=.o)


all:$(NAME)

$(NAME) : $(OBJS)
	$(ARS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re