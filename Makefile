# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwong <juwong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 11:00:07 by juwong            #+#    #+#              #
#    Updated: 2018/09/06 12:56:26 by juwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = sources/*.c

HEADER = includes/*.h

LIBFT = -L./libft -lft

LIB = libft

all:  $(NAME)

$(NAME):
	@gcc -g -c $(SRC) -I$(HEADER)
	@make -C $(LIB)
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all
