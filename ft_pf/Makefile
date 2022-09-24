# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:09:02 by rchiewli          #+#    #+#              #
#    Updated: 2022/09/19 16:57:57 by rchiewli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a
CFLAGS	= -Wall -Werror -Wextra -c
FILES	= ft_printf.c\
			libftmodified.c\
			ft_itoa.c

OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
