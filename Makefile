# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:24:03 by angellop          #+#    #+#              #
#    Updated: 2025/05/18 08:53:30 by angellop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombres de los ejecutables
NAME = fractol

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# Directorios
LIBFT_DIR = ./utils
MLX_DIR = ./utils/MLX42

# Archivos fuente de los programas
SRC = main.c \
	  mandelbrot.c \
	  julia.c \
	  burning_ship.c \
	  utils.c \
	  prerequisites.c \
	  controls.c \
	  colors.c

# Archivos objeto de los programas
OBJ = $(SRC:.c=.o)

# Archivos objeto de las librerías
OBJ_LIBFT = $(LIBFT_DIR)/libft.a

# Cabeceras
HEADERS	:= -I ./utils/includes -I $(MLX_DIR)/include
MLX_LIBS	:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Correct the use of HEADERS by adding it to CFLAGS
CFLAGS += $(HEADERS)

# Regla principal para compilar todo
all: libmlx $(NAME)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

# Regla para compilar el ejecutable
$(NAME): $(OBJ) $(OBJ_LIBFT)
	$(CC) $(OBJ) $(MLX_LIBS) $(CFLAGS) $(OBJ_LIBFT) -o $(NAME)

# Compile each source file into its corresponding object file
$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar la librería libft
$(OBJ_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Regla para limpiar los objetos generados
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
	rm -rf $(MLX_DIR)/build

# Regla para limpiar todo (incluso los binarios generados)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Regla para hacer un 'rebuild' completo
re: fclean all

.PHONY: all clean fclean re libmlx
