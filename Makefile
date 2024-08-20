# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 14:59:12 by hladeiro          #+#    #+#              #
#    Updated: 2024/08/20 19:02:43 by hladeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAMESV = server
LIBFT = libft
printf = cd  ft_printf && make
PRF = libftprintf.a
CP = cp ft_printf/libftprintf.a .
RM = rm -rf
CC = cc
FLAGS = -Wall -Wextra -Werror

CL_FILES = client.c
SR_FILES = server.c

OBJCL = $(CL_FILES:.c=.o)
OBJSR = $(SR_FILES:.c=.o)

all:
	$(printf)
	$(CP)
	@make start

start: $(NAME) $(NAMESV)

$(NAME): $(OBJCL)
	$(CC) $(FLAGS) $(OBJCL) $(PRF) -o $(NAME)

$(NAMESV): $(OBJSR)
	$(CC) $(FLAGS) $(OBJSR) $(PRF) -o $(NAMESV)

clean:
	$(RM) $(OBJCL) $(OBJSR)
	$(printf) clean

fclean:	clean
		$(RM) $(NAME) $(NAMESV) $(PRF)
		$(printf) fclean

re:	fclean all 
