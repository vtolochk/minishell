# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 20:20:18 by vtolochk          #+#    #+#              #
#    Updated: 2018/04/19 13:34:14 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

HEADER = includes/minishell.h

SRCS = minishell.c run_commands.c copy_env.c list_functions.c \
	   echo.c env.c setenv.c unsetenv.c remove_quotes.c count_sign.c \
	   pwd.c cd.c execute_files.c new_array.c array_len.c remove_dollar.c \
	   remove_tild.c new_process.c list_functions_2.c is_dir.c

OBJ = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: lib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) libft/libft.a
	gcc $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

lib:
	make -C ./libft/

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
