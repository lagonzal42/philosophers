# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:41:25 by larra             #+#    #+#              #
#    Updated: 2023/10/03 19:13:47 by lagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#directories
SRC_DIR = src/
OBJ_DIR = obj/
INCS = incs

#files
SRCS =	00_main\
	01_check_parameters\
	02_error_msg\
	03_create_philos\
	04_free_elements

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -fr

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) $(OBJF)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INCS)
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
