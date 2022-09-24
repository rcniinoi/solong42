# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:09:02 by rchiewli          #+#    #+#              #
#    Updated: 2022/09/24 21:59:35 by rchiewli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= solong
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
FILES	= solongmain.c \
			solongini.c \
			solonghand.c \
			gnlpush/get_next_line.c \
			gnlpush/get_next_line_utils.c \
			srcshow/solongoutput1.c \
			srcshow/solongoutput2.c \
			solonghookf/solonghooker1.c \
			solonghookf/solonghooker2.c \
			enemy/solongdeath.c \
			enemy/solongenemy.c \
			enemy/solonghastur.c \
			enemy/solongplamuk.c \
			enemy/solongplamukini.c \
			directorymapngongo/solongcepchk.c \
			directorymapngongo/solongfloodlikeladkrabang.c \
			directorymapngongo/solongmapchk.c \
			directorymapngongo/solongpaiaopantiima.c

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit


OBJ	= $(FILES:%.c=%.o)

all:  $(NAME)

# ft_pf:
# 	@make -C ft_pf/

$(NAME): $(OBJ)
	@make -C ft_pf/
	@make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) ft_pf/libftprintf.a -o $@ $(MLX_FLAG)

love:
	@printf "No one to \e[1;31m make love \e[0m with you."

norm:
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine solong.h

clean:
	@rm -f $(OBJ)
	@make clean -C ft_pf/
	@make clean -C mlx/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_pf/

re: fclean all

.PHONY: clean fclean all re norm love
