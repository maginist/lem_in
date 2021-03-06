# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maginist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 11:22:24 by maginist          #+#    #+#              #
#    Updated: 2019/05/27 16:59:53 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME = already_exist.c\
		  extract_room.c\
		  find_path.c\
		  free_lst.c\
		  is_valid.c\
		  main.c\
		  main2.c\
		  make_matrix.c\
		  paths_utils.c\
		  put_wth.c\
		  stock_data.c\
		  utils.c\
		  write_data.c\
		  nodes.c\
		  gest_args.c\
		  way_is.c\
		  other_path.c\
		  init_struct.c\
		  shortcut.c\

SRC_PATH = ./src

OBJ_PATH = ./obj

INC = -I./includes

LIB = libprintf/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# Colors
CK = $'\033[30m$'
_RED = $'\033[31m$'
_GREEN = $'\033[32m$'
_YELLOW = $'\033[33m$'
_BLUE = $'\033[34m$'
_PURPLE = $'\033[35m$'
_CYAN = $'\033[36m$'
_GREY = $'\033[37m$'
_END=$'\033[0m$'

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ)
		@make -C $(LIB) -j
		@cp libprintf/libprintf.a .
		@echo "$(_GREEN)[ LIBPRINTF DONE ]$(_END)"
		@echo "\n"
		@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
		@echo "|    COMPILING LEM_IN    |"
		@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
		@echo "\n"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libprintf.a
		@echo "$(_GREEN)[ LEM_IN DONE ]$(_END)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
		@$(CC) $(CFLAGS) -I $(LIB) -c $? -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean :
	@make clean -C $(LIB)
	@rm -rf $(OBJ_PATH)
	@echo "$(_BLUE)======< CLEAN PROJECT & LIBPRINTF DONE >======$(_END)"
	@rm -f ./libprintf.a

fclean : clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)
	@echo "$(_BLUE)======< FCLEAN PROJECT & LIBPRINTF DONE >======$(_END)"

re : fclean all

.PHONY : all clean fclean re
