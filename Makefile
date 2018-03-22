# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 20:20:18 by vtolochk          #+#    #+#              #
#    Updated: 2018/03/22 20:39:50 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

HEADER = includes/minishell.h

#LIB_HEADER = libft/includes/*.h

#LIB_SRCS = libft/srcs/*.c

SRCS = minishell.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME) 
	#$(LIBFT) 

#libft/srcs/%.o: $(LIB_SRCS) $(LIB_HEADER)
#	make -C ./libft/ re

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
