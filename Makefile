# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#              #
#    Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)

INC = -I. -I$(LIBFT_DIR)
OBJ_DIR = obj

SRC = main.c \
      utils.c \
      error.c \
      parse.c \
      parse_num.c \
      validate.c \
      emit.c \
      stack.c \
      ops.c \
      ops_rot.c \
      ops_rrot.c \
      sort.c \
      sort_simple.c \
      sort_medium.c \
      sort_complex.c \
      sort_adaptive.c \
      disorder.c \
      bench.c \
      bench_fmt.c \
      move.c \
      sort_small.c \
      sort_lis.c \
      insert.c \
      insert_rot.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(LIBFT): $(LIBFT_SRC) $(LIBFT_DIR)/libft.h
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "push_swap built."

$(OBJ_DIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "push_swap object files cleaned."

fclean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "push_swap removed."

re: fclean all

.PHONY: all clean fclean re
