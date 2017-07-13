# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/20 10:10:12 by amarquez          #+#    #+#              #
#    Updated: 2017/07/11 17:39:21 by amarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler

CC	= gcc
LINKER = gcc

# Flags

FLAGS = -Wall -Wextra -Werror

# Project Directory

CWD = .

# Genereic File Structure

INCDIR = $(CWD)/inc
SRCDIR = $(CWD)/src
OBJDIR = $(CWD)/obj

# Include Files

INC := $(wildcard $(INCDIR)/*.h)
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# lib name

TARGET = libftp.a

# Bin directory

BINDIR = .

##### NB: Check if directories exists before you try to use them

# rules begin:

$(BINDIR)/$(TARGET): $(OBJ)
	@echo "\033[0;31m[libftp]: \033[0m\033[0;36mLinking object files!\033[0m"
	@ar rc $(TARGET) $(OBJ)
	@ranlib $(TARGET)
	@echo "\033[0;31m[libftp]: \033[0m\033[0;32mLinking complete!\033[0m"


$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@make --silent -C ../libft
	@echo "\033[0;31m[libftp]: \033[0m\033[0;36mCompiling source file "$<"!\033[0m"
	@$(CC) $(FLAGS) -c $< -o $@ -L ../libft -lft -I $(INCDIR) -I ../libft
	@echo "\033[0;31m[libftp]: \033[0m\033[0;32mCompiled "$<" successfully!\033[0m"


.PHONY: clean
clean:
	@echo "\033[0;31m[libftp]: \033[0m\033[0;36mRemoving object files\033[0m"
	@rm -f $(OBJ)
	@echo "\033[0;31m[libftp]: \033[0m\033[0;32mCleanup complete\033[0m"


.PHONY: fclean
fclean: clean
	@make fclean --silent -C ../libft
	@echo "\033[0;31m[libftp]: \033[0m\033[0;36mRemoving executables '$(BINDIR)/$(TARGET)'\033[0m"
	@rm -f $(BINDIR)/$(TARGET)
	@echo "\033[0;31m[libftp]: \033[0m\033[0;32mlib removed\033[0m"


.PHONY: re
re: fclean all


norm:
	@echo "\033[0;31m[libftp]: \033[0m\033[0;36mnorming files!\033[0m"
	@norminette $(SRC)

