# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grannou <grannou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 01:35:59 by grannou           #+#    #+#              #
#    Updated: 2023/01/14 06:53:06 by grannou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = ircserv

# Shell used and delete command
SHELL = /bin/sh
RM = /bin/rm -rf

# Files suffixes
.SUFFIXES: .cpp .o .hpp

# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP -g3 -Ofast -fsanitize=address
# CXXFLAGS += -pedantic -Weffc++ -Wconversion
CPPFLAGS = -I$(INCLUDES_DIR)

# Source files
SRCS_FILES = 		main.cpp \
					Server.cpp \
					Channel.cpp \
					User.cpp

# Header files
INCLUDES_FILES =	Server.hpp \
					Channel.hpp \
					User.hpp \
					Cmd.hpp \
					Rpl_Answer \
					Include.hpp

# Objects files built from .cpp files
OBJS = $(SRCS_FILES:%.cpp=%.o)

# Dependencies files (handles .hpp modifications)
DEPS = $(SRCS_FILES:%.cpp=%.d)

# Includes and sources directories
INCLUDES_DIR = includes
SRCS_DIR = srcs

# Add prefixes to files
vpath %.cpp $(foreach dir, $(SRCS_DIR), $(dir):)
INC = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

# Program arguments server port and password
ARGUMENTS = 6667 password

# Rules (all must be first)
.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033c"
	@echo "\n"
	@echo "$(shell tput setaf 198)██╗ ██████╗   ██████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ██╔══██╗ ██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)██║ ██████╔╝ ██║     $(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██║ ██╔══██╗ ██║     $(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██║ ██║  ██║ ╚██████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)╚═╝ ╚═╝  ╚═╝  ╚═════╝$(shell tput sgr0)"

	@echo "$(shell tput setaf 198)██╗███╗   ██╗████████╗███████╗██████╗ ███╗   ██╗███████╗████████╗    ██████╗ ███████╗██╗      █████╗ ██╗   ██╗     ██████╗██╗  ██╗ █████╗ ████████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║████╗  ██║╚══██╔══╝██╔════╝██╔══██╗████╗  ██║██╔════╝╚══██╔══╝    ██╔══██╗██╔════╝██║     ██╔══██╗╚██╗ ██╔╝    ██╔════╝██║  ██║██╔══██╗╚══██╔══╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)██║██╔██╗ ██║   ██║   █████╗  ██████╔╝██╔██╗ ██║█████╗     ██║       ██████╔╝█████╗  ██║     ███████║ ╚████╔╝     ██║     ███████║███████║   ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██║██║╚██╗██║   ██║   ██╔══╝  ██╔══██╗██║╚██╗██║██╔══╝     ██║       ██╔══██╗██╔══╝  ██║     ██╔══██║  ╚██╔╝      ██║     ██╔══██║██╔══██║   ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██║██║ ╚████║   ██║   ███████╗██║  ██║██║ ╚████║███████╗   ██║       ██║  ██║███████╗███████╗██║  ██║   ██║       ╚██████╗██║  ██║██║  ██║   ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 214)╚═╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝       ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝   ╚═╝        ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   $(shell tput sgr0)"
	@echo "\n"

	@echo "$(shell tput setaf 255)              grannou                            ejahan                           efinicke         $(shell tput sgr0)" 

	@echo "$(shell tput setaf 214)   ▄▄▄▄▄▄▄ ▄▄      ▄  ▄  ▄▄▄▄▄▄▄      ▄▄▄▄▄▄▄   ▄ ▄   ▄  ▄  ▄▄▄▄▄▄▄      ▄▄▄▄▄▄▄ ▄▄▄ ▄ ▄▄▄   ▄ ▄▄▄▄▄▄▄$(shell tput sgr0)" 
	@echo "$(shell tput setaf 208)   █ ▄▄▄ █ ▄  ▄▄▄█▄▄▀▀ █ █ ▄▄▄ █      █ ▄▄▄ █ ▀ ▀ ▄ ▄▀  ▄▄▄ █ ▄▄▄ █      █ ▄▄▄ █ █▀█▄ ▀█  ▄ ██ █ ▄▄▄ █$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)   █ ███ █ ██▄█ ███████▄ █ ███ █      █ ███ █ ▀█▀ ▀█▀ ▄▀▀█  █ ███ █      █ ███ █ ▀▀ ▀ ▀███  ▀▄ █ ███ █$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)   █▄▄▄▄▄█ ▄▀▄ █ █ ▄▀▄▀█ █▄▄▄▄▄█      █▄▄▄▄▄█ █▀▄▀█ ▄▀█▀█ █ █▄▄▄▄▄█      █▄▄▄▄▄█ █ ▄▀█ ▄ █▀█▀▄ █▄▄▄▄▄█$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)   ▄▄▄▄  ▄ ▄▀ ▀  █▀██ ▄▀▄  ▄▄▄ ▄      ▄▄▄▄▄ ▄▄▄█▀█ ▄▄█▀▄█  ▄ ▄ ▄ ▄       ▄▄  ▄▄▄  ▀ ▄▀  ▀ █▄▄▄  ▄ ▄▄▄▄$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)       █ ▄▄ ▀   █  █▀█▀█▀███ ▄▄▀      ▄▄█▄▀▄▄▀█ █ ▀  ▄██▀▀▀██▀▀   ▀      ▀ ▄█▄█▄▄▀▀▀▄█ ▀█▀▀█  ▄▀██▀▀▀█$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)    ▀▄▀█▄▄█ ▄ █▀█▄▀ ▄  ▄▀▀▀ ▄▄ ▀      ▄█ ▀ ▀▄▀█▄▄ █▄█ ▀▄▀▀▄  ▀▀█▄▀       █ ▀ ██▄▄█ █▀▄ ▀▄ █ █ ▄▀  ▀ █▀$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)   ▀█  █ ▄▀▀█▀▀▄▀█▀ █▄█ ▄▀▄▄ ███      █▄ ▄▀▀▄██▀ ▄▄█▄▄▄▄▀▀▀▀██▀▄▄ ▀       █▄▀██▄ █▀▄  █▀█  █   ▀▀███▀█$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)   █▄█ ▄▀▄█▀▀▀▄▀▄▀ ▄ █ ▀█ █▄▄ █       ▄▀▀▄▀█▄▄▄▀▄█   ▄▄▄▀ █▀ ▀ ▄▄▀       ▄▄██▀▀▄▄ █▀▄▀ ▀ ██ ▄▀█▀ ▀  █▀$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)   ▄ █▄▀▀▄█ ▀ ▄█▀██ ▄█ ▀  ▀ ▀█▀       █ ▄▀▄ ▄▀▄██ ▀█▄▄▀▄▄▀▀▀▀▀▀ █ ▀      ▀▀▀█▄ ▄██ █▄█▄▀██     ███▀▄▀█$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)    ▄  ▄█▄█ ▄▀▄█▄ ▀ █ ▀▄█▄█▄▄█        █ ██ █▄ ██  █▀▄▄▄▄███▄▄▄█ ▄█▄      ▄▄██  ▄▀▀ ▀▀▄ ▀ ██▄▀█▄██▄▄ ▀█$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)   ▄▄▄▄▄▄▄ ▀█ ▄██  █▀█▄█ ▄ ██▀█▀      ▄▄▄▄▄▄▄ █▄▀▄▄  ▄██▀▄█ ▄ ███▀▀      ▄▄▄▄▄▄▄ ▀▄█  ▀██▀▀███ ▄ █▄▄ █$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)   █ ▄▄▄ █  ▄▄ ▄ ▄▄ ▄▀ █▄▄▄█▀▄██      █ ▄▄▄ █ ▄ ▄█  ▀█▀▄ ▀█▄▄▄█ ▄█▄      █ ▄▄▄ █ █ ▀▄▀▄█▀ █▀██▄▄▄█▄ ▀▄$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)   █ ███ █ ██▀█▀▄▀▀▀▀███  ▄▀▀▄ █      █ ███ █ █▄▀ ▀██▄█  ▀▄█▄█▄███▀      █ ███ █    ▄█▄██▀▄▄ █▄ ▀ ▄▄▄█$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)   █▄▄▄▄▄█ █  ▀▄ █ ▄ ▄▄█ █▄▀█ █       █▄▄▄▄▄█ █▀  █▀▄▄▄▄ ▄▀▄█ ██▄▀       █▄▄▄▄▄█ ██▄▀▄█  ██▀ █ ▄▀▄▀ █▀$(shell tput sgr0)"
	@echo "\n"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "🦊 $(shell tput setaf 002)OK\t$(shell tput setaf 198)$@ is ready$(shell tput setaf sgr0) 🦊"


-include $(DEPS)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: run
run:
	@echo "$(shell tput setaf 198)       ██╗██╗██████╗  ██████╗███████╗███████╗██████╗ ██╗   ██╗     ██████╗  ██████╗  ██████╗███████╗    ██████╗  █████╗ ███████╗███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗ $(shell tput sgr0)"
	@echo "$(shell tput setaf 197)      ██╔╝██║██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗██║   ██║    ██╔════╝ ██╔════╝ ██╔════╝╚════██║    ██╔══██╗██╔══██╗██╔════╝██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)     ██╔╝ ██║██████╔╝██║     ███████╗█████╗  ██████╔╝██║   ██║    ███████╗ ███████╗ ███████╗    ██╔╝    ██████╔╝███████║███████╗███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)    ██╔╝  ██║██╔══██╗██║     ╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝    ██╔═══██╗██╔═══██╗██╔═══██╗  ██╔╝     ██╔═══╝ ██╔══██║╚════██║╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██╗██╔╝   ██║██║  ██║╚██████╗███████║███████╗██║  ██║ ╚████╔╝     ╚██████╔╝╚██████╔╝╚██████╔╝  ██║      ██║     ██║  ██║███████║███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)╚═╝╚═╝    ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝       ╚═════╝  ╚═════╝  ╚═════╝   ╚═╝      ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ $(shell tput sgr0)"
	@./$(NAME) $(ARGUMENTS)

# No more norme... but still Norminet ;)
.PHONY: norme
norme:
	@echo "\033c"
	@echo "\n"
	@echo "$(shell tput setaf 46)No more norme... but still$(shell tput sgr0)"
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║   $(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝   $(shell tput sgr0)"
	@echo "\n"

# Debug with valgrind
.PHONY: debug
debug:
	@echo "\n"
	@echo "$(shell tput setaf 201)██████╗ ███████╗██████╗ ██╗   ██╗ ██████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)██╔══██╗██╔════╝██╔══██╗██║   ██║██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██║  ██║█████╗  ██████╔╝██║   ██║██║  ███╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║  ██║██╔══╝  ██╔══██╗██║   ██║██║   ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██████╔╝███████╗██████╔╝╚██████╔╝╚██████╔╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═════╝ ╚══════╝╚═════╝  ╚═════╝  ╚═════╝$(shell tput sgr0)"
	@echo "\n"
	valgrind --leak-check=full ./$(NAME) $(ARGUMENTS)

# Clean objects (.o) and dependencies (.d)
.PHONY: clean
clean: 
	@echo "\033c"
	@echo "\n"
	@echo "$(shell tput setaf 51) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 50)██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 49)██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 48)██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 47)╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 46) ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"
	$(RM) $(OBJS) $(DEPS)

# Execute clean and clean program
.PHONY: fclean
fclean: clean
	@echo "\033c"
	@echo "\n"
	@echo "$(shell tput setaf 45)███████╗ ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 44)██╔════╝██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 43)█████╗  ██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 42)██╔══╝  ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 41)██║     ╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 40)╚═╝      ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"
	$(RM) $(NAME)

# Clean all and make
.PHONY: re
re: fclean all
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ███╗ █████╗ ██╗  ██╗███████╗    ██████╗ ███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ██╔══██╗██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔████╔██║███████║█████╔╝ █████╗      ██████╔╝█████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██╔══██╗██╔══╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║  ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝$(shell tput sgr0)"
	@echo "\n"

# Bonus compilation
.PHONY: bonus
bonus: $(OBJS_BONUS)
	@echo "\033c"
	@echo "\n"
	@echo "$(shell tput setaf 226)██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 220)██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝$(shell tput sgr0)"
	@echo "\n"
	
# Best rule <3
.PHONY: fox
fox:
	@echo "\033c"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂∂$(shell tput setaf 202)ΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)      $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)     $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈$(shell tput setaf 94)∂$(shell tput sgr0)   $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput setaf 40)@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈$(sh    ell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)     :::::$(shell tput sgr0)     $(shell tput sgr0)ΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)             $(shell tput sgr0)ΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)           $(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)         ΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ::$(shell tput sgr0)$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)::ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0):::$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)ΩΩΩΩ:::$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩ$(shell tput setaf 196)Ω$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
