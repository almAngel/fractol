# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 16:29:58 by angellop          #+#    #+#              #
#    Updated: 2025/04/09 17:49:32 by angellop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

LIBFT_DIR = ./libft/
PRINTF_DIR = ./ft_printf/
INCLUDES_DIR = ./includes

MY_SOURCES = $(addprefix $(LIBFT_DIR), ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c)\
		$(addprefix $(PRINTF_DIR), ft_printf.c\
		ft_todecimal.c\
		ft_tohex.c\
		ft_tostringnchar.c)

CC 		= cc

OBJS	= $(MY_SOURCES:.c=.o)

RM		= rm -f

LIBC	= ar -rcs

FLAGS	= -fPIC -Wall -Wextra -Werror -I $(INCLUDES_DIR)

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
