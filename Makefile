# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 19:55:10 by koito             #+#    #+#              #
#    Updated: 2025/12/15 19:55:11 by koito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = execute_sort.c \
		ft_atoi_check_ps.c \
		ft_split_ps.c \
		in_sort_number_helper.c \
		in_sort_number.c \
		order_check.c \
		pa_ps.c \
		pb_ps.c \
		push_swap.c \
		ra_rb_ps.c \
		rr_ps.c \
		rra_rrb_ps.c \
		rrr_ps.c \
		sa_ps.c \
		sb_ps.c \
		sort_2_3.c \
		sort_4_5.c \
		ss_ps.c \
		stacks_free_null.c \
		index_stack.c

OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDE_DIR = include

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

.PHONY: all clean fclean re

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all


