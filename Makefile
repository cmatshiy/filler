# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 10:59:46 by cmatshiy          #+#    #+#              #
#    Updated: 2018/08/16 10:19:11 by cmatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = filler.c get_next_line.c ft_get_info.c ft_check_pos.c ft_map_piece.c ft_check_place_piece.c\
      ft_maps.c ft_trim.c ft_use_mind.c ft_puttrace.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft
	gcc -I libft/ -c $(SRC)
	gcc $(CFLAG) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)

q:
	gcc -I libft/ -c $(SRC)
	gcc $(CFLAG) -o $(NAME) $(OBJ) -L libft/ -lft

run:
	rm trace.txt
	touch trace.txt
	./filler_vm -p1 ./resources/players/carli.filler -p2 ./filler -v -f resources/maps/map02

qr: q run
