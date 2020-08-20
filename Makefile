# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ukelly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 03:14:17 by ukelly            #+#    #+#              #
#    Updated: 2020/03/02 03:14:28 by ukelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -o2

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft -I include
LIBS = -L libft -lft -lmlx -framework OpenGL -framework AppKit

SRC = additional_projections get_next_line key projection projection_rotate render  color init main projection_epileptic reader utils
INC = include/errors.h include/fdf.h include/get_next_line.h include/keys.h

SRC_C = $(patsubst %, %.c, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %, %.o, $(SRC)))

.PHONY: all clean fclean re make_lib

all: $(NAME)

$(OBJ_DIR):
	mkdir -vp obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all