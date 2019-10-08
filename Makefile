# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 08:11:00 by cacharle          #+#    #+#              #
#    Updated: 2019/10/08 11:52:21 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(RM) = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra #-Werror -D BUFFER_SIZE=32

NAME = get_next_line
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
INCLUDE = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
