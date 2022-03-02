# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 23:04:08 by wrolanda          #+#    #+#              #
#    Updated: 2022/03/03 00:24:28 by wrolanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c				validation_of_in_data.c		frees.c\
			work_with_stack.c	ft_push_swap.c			instructions_a.c\
			./experiments/main_check.c\
			ft_strlen.c		ft_atoi.c		ft_split.c\


SRCS_B	=

HEADER	=	push_swap.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# $? - The names of all prerequisites (separated by spaces) that are "newer" than the target

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
# $<- The name of the first prerequisite.
# $@ - The file name of the target of the rule. If the target is an archive member, then '$ @' denotes the name of the archive file.

bonus	:
	@make OBJ="$(OBJ_B)" all

clean	:
	rm	-f $(OBJ) $(OBJ_B)

fclean	:	clean
	rm	-f $(NAME)

re	:	fclean all
