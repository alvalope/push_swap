# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 10:15:01 by alvalope          #+#    #+#              #
#    Updated: 2023/06/08 14:02:42 by alvalope         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = ./libftplus

LIBFT = $(LIBFT_PATH)/libft.a

HEADER = ft_push_swap.h $(LIBFT_PATH)/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push_swap.c ft_push_swap_utils2.c ft_ops_ps.c \
	ft_ops_rr.c ft_push_swap_small.c ft_push_swap_bigger.c ft_do_r_and_rr.c

OBJS = $(SRCS:.c=.o)

COMMON_SRCS = ft_check_nb.c ft_memory_free.c ft_push_swap_utils.c \
	ft_calculate_cost.c ft_list_utils.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

BONUS_SRCS = ft_checker_bonus.c ft_ops_ps_bonus.c ft_ops_rr_bonus.c \
	ft_checker_utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

BONUS_NAME = checker

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(OBJS): $(SRCS) $(COMMON_SRCS)
	@echo "Compilando archivos de push_swap..."
	@$(CC) $(CFLAGS) -c $(SRCS) $(COMMON_SRCS)

$(NAME): $(OBJS) $(COMMON_OBJS) $(LIBFT) $(HEADER)
	@echo "Compilando ejecutable..."
	@$(CC) $(CFLAGS) $(OBJS) $(COMMON_OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[0;32mPROCESO TERMINADO.\033[0m"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT) $(HEADER)
	@echo "Compilando ejecutable..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "\033[0;32mPROCESO TERMINADO.\033[0m"

$(BONUS_OBJS): $(BONUS_SRCS) $(COMMON_SRCS)
	@echo "Compilando archivos del checker..."
	@$(CC) $(CFLAGS) -c $(BONUS_SRCS) $(COMMON_SRCS)
	
ps: all clean

chk: bonus clean

clean:
	@echo "\033[0;31mBorrando archivos generados en la compilacion...\033[0m"
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS) $(BONUS_OBJS) $(COMMON_OBJS)
	@echo "\033[0;33mLIMPIEZA TERMINADA.\033[0m"

fclean: clean
	@echo "\033[0;31mBorrando librerias generadas...\033[0m"
	@make -C $(LIBFT_PATH) libclean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[0;33mLIMPIEZA TOTAL TERMINADA.\033[0m"

re: fclean all

.PHONY: all clean fclean re