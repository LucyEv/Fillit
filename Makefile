# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 21:31:12 by ikozlov           #+#    #+#              #
#    Updated: 2019/05/06 15:00:56 by ivankozlov       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

# compiler
CC = gcc
DEBUG = -g
ENV = ${C_ENV}
ifeq ($(ENV), DEV)
	FLAGS = $(DEBUG)
else ifeq ($(ENV), PROD)
	FLAGS = -Wall -Wextra -Werror
endif

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# full paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libraries
LIBFT = $(LIBFT_DIR)libft.a
LIB = $(LIBFT)

# includes
INCLUDES = -I $(LIBFT_DIR)includes -I $(INC_DIR)

all: $(NAME)

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) libft/libft.a -o $(NAME) $(OBJ)
	@echo "[INFO] $(NAME) executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		/bin/rm -rf $(OBJ_DIR);\
		/bin/echo "[INFO] Objects removed.";\
	fi;

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
		/bin/echo "[INFO] $(NAME) executable deleted";\
	fi;

re: fclean all

.PHONY: all $(NAME) clean fclean re norm