# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larra <larra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:41:25 by larra             #+#    #+#              #
#    Updated: 2023/07/18 13:41:25 by larra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#directories
SRC_DIR = src/
OBJ_DIR = obj/
INCS = incs

#files
SRCS =	00_main\
		01_check_args

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -fr
AR = ar rcs

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean:
	$(RM) $(NAME)

re: fclean all

norm:
	norminnette  $(SRC_DIR) $(INCS)

.PHONY: all clean fclean re norm
