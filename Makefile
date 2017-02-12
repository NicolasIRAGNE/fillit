# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 15:05:20 by niragne           #+#    #+#              #
#    Updated: 2017/02/12 19:19:25 by fdille           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	ft_checkfile.c \
		ft_search_mapsize.c \
		ft_read.c \
		tetris.c \
		putsol.c \
		main.c \
		fillit.c

LIB = libft/libft.a
GREEN= \033[0;32m
NC= \033[0m
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Making lib..."
	@make -C libft
	@echo "Compiling objects into executable..."
	@gcc -o $(NAME) $(OBJ) -L . $(LIB)
	@echo "${GREEN}Success !${NC}"

clean:
	@make -C libft clean
	@echo "Removing objects..."
	@rm -f $(OBJ)
	@echo "${GREEN}Success !${NC}"

fclean: clean
	@make -C libft fclean
	@echo "Removing executable..."
	@rm -f $(NAME) $(LIB)
	@echo "${GREEN}Success !${NC}"

re: fclean all
		
