# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 08:11:00 by cacharle          #+#    #+#              #
#    Updated: 2019/10/08 08:21:06 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH = ./libft

CC = gcc
CCFLAGS = -Wall -Wextra #-Werror
LDFALGS = -L./libft -lft
INCLFLAGS = -I./libft

NAME = get_next_line
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)
INCLUDE = get_next_line.h

$(RM) = rm -f

# Makefile must not relink ??

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	make -C $(LIBFTPATH)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(INCLFLAGS) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
