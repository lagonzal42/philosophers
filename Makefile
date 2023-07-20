# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larra <larra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:41:25 by larra             #+#    #+#              #
#    Updated: 2023/07/20 14:03:56 by larra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#directories
SRC_DIR = src/
OBJ_DIR = obj/
INCS = incs

#files
SRCS =	00_main\
		01_check_args\
		02_create_philos\
		03_ft_error

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -fr
AR = ar rcs

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) $(OBJF)
	@$(CC) $(CFLAGS) -c $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)



clean:
	@$(RM) $(OBJ_DIR)

fclean:
	@$(RM) $(NAME)

re: fclean all

norm:
	norminnette  $(SRC_DIR) $(INCS)

.PHONY: all clean fclean re norm
