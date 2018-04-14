# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:58:03 by abiestro          #+#    #+#              #
#    Updated: 2018/04/14 14:28:14 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
INCLUDES=../includes/fillit.h
SRCS= srcs/main.c \
	  srcs/parse.c \


OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
