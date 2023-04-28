# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstrstudent.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/05 15:18:40 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/10/31 15:59:02 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	main.c							\
		move.c							\
		checkers.c						\
		mlx.c							\
		images.c						\
		entitys.c						\
		floodfill.c						

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Imlx -g #-fsanitize=address

LIBMLX	= ./MLX42

HEADERS	= $(addprefix -I,						\
				MLX42/include/MLX42				\
				$(LIBFT_DIR)							\
				./								\
				)

LINKFLAGS	= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a

CC = gcc

LIBFT = libft/libft.a
LIBFT_DIR = libft

all: $(NAME)

$(LIBMLX):
	cmake -S $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKFLAGS) $(LIBFT) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $^ -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re