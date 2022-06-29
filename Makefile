# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 11:43:35 by nrenz             #+#    #+#              #
#    Updated: 2022/06/29 18:03:31 by nrenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap_main.c \
		create_lists.c \
		operations.c \
		sort.c \
		sort2.c \
		scoring_program.c \
		transfer_to_a_list.c \
		transfer_to_a_list2.c \
		utils_create_lists.c \
		utils_error_check.c \
		utils_operations_output_1.c \
		utils_operations_output_2.c \
		utils_operations_output_3.c \
		utils_sort.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

leaks:
	make
	leaks --atExit -- ./push_swap -1 0 2 9 3 8 4 7 5 6

.PHONY: all clean fclean re leaks