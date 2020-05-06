# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 23:47:10 by jcruz-y-          #+#    #+#              #
#    Updated: 2020/01/26 18:11:47 by jcruz-y-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of program
NAME := ft_gkrellm

# Directories
INC_DIR := ./includes
SRC_DIR := ./src
OBJ_DIR := ./obj

# Sources and objects
SRC	:=	main.cpp \
		IMonitorDisplay.cpp \
		IMonitorModule.cpp \
	   	TextDisplay.cpp \
		GraphicalDisplay.cpp \
		HostnameModule.cpp \
		OsInfoModule.cpp \
		DateTimeModule.cpp \
		CpuModule.cpp \
		RamModule.cpp \
		NewtowrkModule.cpp \
		FCat.cpp \
		


# HDRS := Fixed.hpp
OBJ := $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o)) #$(SRCS:.cpp=.o)

# Define all compilation flags
CPP := clang++ 
CPPFLAGS := -Wall -Werror -Wextra -g #-fsanitize=address

# Compile and create everything
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# This won't run if the source files don't exist or are not modified
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -I $(INC_DIR) -o $@ -c $< 
	
# Compile the program with the objects
$(NAME): $(OBJ) #$(HDRS)
	@$(CPP) -o $@ $(OBJ) -lncurses 
	
#-fsanitize=address

# Rule to remove all object files
clean:
	@rm -f $(OBJ)
	@echo "[INFO] Objs removed" 

# Rule to remove everything that has been created by makefile
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed"

# Rule to re-make everything
re: fclean all

se: 
# Make sure the gnu compiler runs even if files called
# clean, fclean, all and re already exist in the directory
.PHONY: all clean fclean format re

