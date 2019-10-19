# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 08:11:00 by cacharle          #+#    #+#              #
#    Updated: 2019/10/19 14:49:29 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(RM) = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -g

NAME = get_next_line
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
INCLUDE = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

compare: all
	@./get_next_line Makefile > t1
	@cat -e Makefile | sed 's/^\(.*\)\$$/[\1]/' > t2
	@diff t1 t2


