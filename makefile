# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/05 15:18:40 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/10/31 15:59:02 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c\
move.c\
checkers.c\
mlx.c\
images.c\
entitys.c\
floodfill.c


OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -Imlx -g -fsanitize=address

LIBMLX	= ./MLX42

HEADERS	= -I MLX42/include/MLX42 -I libft

LINKFLAGS	= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit MLX42/libmlx42.a

CC = gcc

LIBFT = LIBFT/libft.a

.PHONY: all, clean, fclean, re, libmlx, libft

all: $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)


$(NAME): $(OBJ) libmlx
	@$(CC) $(CFLAGS) $(OBJ) $(LINKFLAGS) $(LIBFT) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all
