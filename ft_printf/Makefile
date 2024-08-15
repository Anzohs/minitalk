# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 13:24:33 by hladeiro          #+#    #+#              #
#    Updated: 2024/04/30 17:39:39 by hladeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
lib = cd libft && make

SRCS = ft_printf.c ft_printf_write.c ft_printf_bases.c ft_printf_unint.c\
		ft_printf_adr.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CP				= cp
CFLAGS			= -Wall -Wextra -Werror 
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(lib) 
				@cp $(LIBFT) .
				@mv libft.a $(NAME)
				ar rcs $(NAME) $(OBJS) 

clean:
				$(RM) $(OBJS) 
				$(lib) clean

fclean:			clean
				$(RM) $(NAME)
				$(lib) fclean

re:				fclean $(NAME)

test:
				ar -t $(NAME)
.PHONY:			all clean fclean re libft
