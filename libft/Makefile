# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojustine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 17:46:26 by ojustine          #+#    #+#              #
#    Updated: 2019/09/15 19:03:11 by ojustine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_abs.c ft_assert.c ft_atof.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_divmod.c ft_intlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_long_pow.c ft_longlen.c ft_lst_getinx.c ft_lstadd.c ft_lstadd_end.c ft_lstdel.c ft_lstdelinx.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_lstprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_memswap.c ft_moddiv.c ft_pow.c ft_put_unicode.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_realloc.c ft_strany.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcmpi.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnlen.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strrew.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtolower.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_uitoa_base.c ft_uitoa_dec.c ft_uitoa_hex.c ft_ultoa_base.c ft_ultoa_hex.c ft_log_error.c ft_log_info.c ft_strequ_ignore_case.c ft_max.c ft_words_count.c ft_lstrev.c
OBJ = $(SRC:.c=.o)
.PHONY : all clean fclean re
all : $(NAME)
$(NAME) : $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o : %.c libft.h
	gcc -Wall -Werror -Wextra -c $< -o $@
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
