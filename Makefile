# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 11:43:35 by nrenz             #+#    #+#              #
#    Updated: 2022/06/24 11:07:05 by nrenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	create_lists.c \
		push_swap_main.c \
		utils_create_lists.c \
		utils_error_check.c \
		operations.c \
		sort.c \
		sort2.c \
		utils_operations_output_1.c \
		utils_operations_output_2.c \
		utils_operations_output_3.c \
		prepare_transfer_to_a_list.c \
		transfer_to_a_list.c \
		transfer_to_a_list2.c \

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

.PHONY: all clean fclean re