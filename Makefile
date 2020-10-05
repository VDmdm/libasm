# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 11:01:38 by jalvaro           #+#    #+#              #
#    Updated: 2020/05/03 11:01:38 by jalvaro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FILES = ft_read ft_strcmp ft_strcpy ft_strdup ft_strlen ft_write	

BONUS_FILES = ft_atoi_base_bonus ft_list_push_front_bonus 			\
ft_list_size_bonus ft_list_sort_bonus ft_list_remove_if_bonus

SRC_DIR = ./srcs/
SRC_FILE = $(FILES:=.s)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_TEMP = $(addprefix $(SRC_DIR), %.s)


OBJ_DIR = ./obj/
OBJ_FILE = $(FILES:=.o)
OBJ_BONUS = $(BONUS_FILES:=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(OBJ_BONUS))
OBJ_TEMP = $(addprefix $(OBJ_DIR), %.o)

HEADER_FILE = ft.h
HEADER_BONUS_FILE = ft_bonus.h
INCLUDES = ./includes/
HEADER = $(addprefix $(INCLUDES), $(HEADER_FILE))
BONUS_HEADER = $(addprefix $(INCLUDES), $(HEADER_BONUS_FILE))

.PHONY: all clean fclean re bonus

all: $(OBJ_DIR) $(NAME) $(SRC)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Библиотека $(NAME) готова

bonus: $(BONUS_OBJ) $(BONUS_HEADER)
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
	@echo Бонусные файлы в библиотеке $(NAME)

$(OBJ_TEMP): $(SRC_TEMP) 
	@nasm -felf64 $< -o $@
	@echo Собираю $@ из $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean: 
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f libasm.a
	@echo libasm: Все очищено

re: fclean all
