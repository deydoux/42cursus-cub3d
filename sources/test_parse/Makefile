# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 14:23:53 by mapale            #+#    #+#              #
#    Updated: 2024/10/18 12:33:48 by mapale           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	parse
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g3 #-fsanitize=address
HEADER_FILE		=	parse.h
SRCS			=	main.c				\
					safe_fctn.c			\
					parse_map.c			\
					parse_tools.c		\
					parse_doable.c		\
					parse_colors.c		\
					parse_textures.c	\
					parse_initialise.c	\
					error_and_free.c	\
					DELETE.c			\

OBJS			= $(SRCS:.c=.o)

LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBFT_MAKE		= $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c $(HEADER_FILE) $(LIBFT) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR):
	$(LIBFT_MAKE)

$(LIBFT): $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_DIR)
