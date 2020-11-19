# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkoriaki <dkoriaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 16:26:48 by dkoriaki          #+#    #+#              #
#    Updated: 2020/11/19 17:54:51 by dkoriaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

HEADER	=	./includes/cub3d.h

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)/libft.a

MLX_DIR	=	./minilibx-linux/
MLX			=	$(MLX_DIR)/libmlx.a

SRCS	=	./srcs/main.c \
			./srcs/ft_utils.c

OBJS	=	$(SRCS:.c=.o)

INCLUDES	=	./includes

CC			=	clang

HEAD		=	-I./$(INCLUDES) -I./$(LIBFT_DIR) -I./$(MLX_DIR)

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

LFLAGS 		=	-lbsd -lm -lX11 -lXext \
					-L ./$(LIBFT_DIR) -lft \
					-L ./$(MLX_DIR) -lmlx

all				:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(MLX)
				$(CC) $(OBJS) $(HEAD) $(CFLAGS) $(LFLAGS) -o $@

%.o: %.c $(HEADER)
			$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
				make -C $(LIBFT_DIR)

$(MLX):
				make -C $(MLX_DIR)

clean:
				make clean -C $(LIBFT_DIR)
				rm -f $(OBJS)

fclean:	clean
				make fclean -C $(LIBFT_DIR)
				rm -f $(NAME)
				rm -f *.bmp

re:	fclean all

run: all
			./Cub3D

.PHONY:	all clean fclean re
