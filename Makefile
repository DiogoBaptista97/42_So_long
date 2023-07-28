# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:05:29 by dbraga-b          #+#    #+#              #
#    Updated: 2022/11/23 16:05:31 by dbraga-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
RM = rm -rf

SRCS = checkmap.c checkmap_aux.c so_long.c fazmap.c fazmapimages.c so_long_aux.c fazmapimages_aux.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-director -C ./libft
	
$(NAME): $(OBJS) $(LIBFT)
		$(MAKE) --no-print-director -C ./mlx
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) libft/libft.a $(MLXFLAGS) -o $(NAME)

clean:
		$(MAKE) clean --no-print-director -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean --no-print-director -C ./libft
		$(RM) libft.a
		$(RM) $(MAKE)

re: fclean all
