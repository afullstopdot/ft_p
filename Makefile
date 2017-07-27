# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/20 10:10:12 by amarquez          #+#    #+#              #
#    Updated: 2017/07/14 10:10:49 by amarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler

CC	= gcc
LINKER = gcc

# Flags

FLAGS = -Wall -Wextra -Werror -g3

# Project Directory

CWD = .

# Genereic File Structure

INCDIR = $(CWD)/inc
SRCDIR = $(CWD)/src
OBJDIR = $(CWD)/obj

# Server & Client directories

SERVER_DIR = server
CLIENT_DIR = client

# Include Files

INC := $(wildcard $(INCDIR)/*.h)

# Server & Client source Files

SERVER_SRC := $(wildcard $(SRCDIR)/$(SERVER_DIR)/*.c)
CLIENT_SRC := $(wildcard $(SRCDIR)/$(CLIENT_DIR)/*.c)

# Server & Client object Files

SERVER_OBJ := $(SERVER_SRC:$(SRCDIR)/$(SERVER_DIR)/%.c=$(OBJDIR)/$(SERVER_DIR)/%.o)
CLIENT_OBJ := $(CLIENT_SRC:$(SRCDIR)/$(CLIENT_DIR)/%.c=$(OBJDIR)/$(CLIENT_DIR)/%.o)

# libs dependencies

LIBFT 		= -L ./libft -lft
LIBFTP 		= -L ./libftp -lftp
LIBFT_H 	= -I libft
LIBFTP_H 	= -I libftp/inc


# Executabe name

SERVER = server
CLIENT = client

# OS for linking libraries (linux and os x different)

OS := $(shell uname)

ifneq ($(OS),Darwin)
  LINK = $(LIBFTP) $(LIBFT)
endif

# Bin directory

BINDIR = .

##### NB: Check if directories exists before you try to use them

# rules begin:

all: $(OBJDIR) $(BINDIR)/$(SERVER) $(BINDIR)/$(CLIENT)

$(OBJDIR):
	@echo "\033[0;31m[server]: \033[0m\033[0;36mCreating "$@" directory!\033[0m"
	@mkdir -p $@/$(SERVER_DIR) $@/$(CLIENT_DIR)
	@echo "\033[0;31m[server]: \033[0m\033[0;32mComplete!\033[0m"

$(BINDIR)/$(SERVER): $(SERVER_OBJ)
	@echo "\033[0;31m[server]: \033[0m\033[0;36mLinking object files!\033[0m"
	@$(LINKER) $(SERVER_OBJ) $(FLAGS) -o $@ $(LIBFTP) $(LIBFT) -I $(INCDIR) $(LIBFTP_H) $(LIBFT_H)
	@echo "\033[0;31m[server]: \033[0m\033[0;32mLinking complete!\033[0m"


$(SERVER_OBJ): $(OBJDIR)/$(SERVER_DIR)/%.o : $(SRCDIR)/$(SERVER_DIR)/%.c
	@make --silent -C libftp	
	@echo "\033[0;31m[server]: \033[0m\033[0;36mCompiling source file "$<"!\033[0m"
	@$(CC) $(FLAGS) -c $< -o $@ $(LINK) -I $(INCDIR) $(LIBFTP_H) $(LIBFT_H)
	@echo "\033[0;31m[server]: \033[0m\033[0;32mCompiled "$<" successfully!\033[0m"


$(BINDIR)/$(CLIENT): $(CLIENT_OBJ)
	@echo "\033[0;33m[client]: \033[0m\033[0;36mLinking object files!\033[0m"
	@$(LINKER) $(CLIENT_OBJ) $(FLAGS) -o $@ $(LIBFTP) $(LIBFT) -I $(INCDIR) $(LIBFTP_H) $(LIBFT_H)
	@echo "\033[0;33m[client]: \033[0m\033[0;32mLinking complete!\033[0m"


$(CLIENT_OBJ): $(OBJDIR)/$(CLIENT_DIR)/%.o : $(SRCDIR)/$(CLIENT_DIR)/%.c
	@make --silent -C libftp	
	@echo "\033[0;33m[client]: \033[0m\033[0;36mCompiling source file "$<"!\033[0m"
	@$(CC) $(FLAGS) -c $< -o $@ $(LINK) -I $(INCDIR) $(LIBFTP_H) $(LIBFT_H)
	@echo "\033[0;33m[client]: \033[0m\033[0;32mCompiled "$<" successfully!\033[0m"


.PHONY: clean
clean:
	@make --silent clean -C libftp	
	@echo "\033[0;36mRemoving object files\033[0m"
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@echo "\033[0;32mCleanup complete\033[0m"


.PHONY: fclean
fclean: clean
	@make --silent fclean -C libftp	
	@echo "\033[0;36mRemoving executables '$(BINDIR)/$(SERVER), $(BINDIR)/$(CLIENT)'\033[0m"
	@rm -f $(BINDIR)/$(SERVER) $(BINDIR)/$(CLIENT)
	@echo "\033[0;32mExecutable removed\033[0m"


.PHONY: re
re: fclean all


norm:
	@echo "\033[0;31m[server]: \033[0m\033[0;36mnorming files!\033[0m"
	@norminette $(SERVER_SRC)
	@echo "\033[0;33m[client]: \033[0m\033[0;36mnorming files!\033[0m"
	@norminette $(CLIENT_SRC)

