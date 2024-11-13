# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 08:44:10 by chorst            #+#    #+#              #
#    Updated: 2024/05/22 16:29:24 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Make Naming
PUSH_SWAP   := push_swap
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -f

# Folder Paths
GNL_DIR     := ext_files/getline
PRINTF_DIR  := ext_files/printf_but_ft
LIBFT_DIR   := ext_files/lib_ft

# Library Paths
GNLLIB      := $(GNL_DIR)/libget_next_line.a
LIBFTLIB    := $(LIBFT_DIR)/libft.a
LIBFTPRINTFLIB := $(PRINTF_DIR)/libprintf.a

# Source Files
SOURCES     :=	files/algorythm.c \
				files/helper_functions.c \
				files/convertion.c \
				files/push_swap.c \
				files/sort_push.c \
				files/sort_reverse.c \
				files/sort_rotate.c \
				files/sort_swap.c \
				files/validation.c \
				files/validation2.c

# Object Files
OBJECTS     := $(SOURCES:.c=.o)

# Define colours
R := \033[0;31m
G := \033[0;32m
Y := \033[0;93m
B := \033[0;94m
D := \033[0m

# Make Rules
all: precomp $(PUSH_SWAP)

precomp:
	@if ls $(OBJECTS) 1> /dev/null 2>&1; then \
		printf "$(G)\nDont panic:$(Y)\n(everything is up to date)\n\n$(D)"; \
	else \
		printf "$(B)\nCompiled $(D)"; \
		printf "$(Y)\n(push_swap)\n$(D)"; \
	fi

$(PUSH_SWAP): $(OBJECTS) $(GNLLIB) $(LIBFTLIB) $(LIBFTPRINTFLIB)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(G)$(notdir $<)$(D)\n"

$(GNLLIB) $(LIBFTLIB) $(LIBFTPRINTFLIB):
	@$(MAKE) -s -C $(@D)

clean:
	@printf "\n$(Y)(push_swap.o)\n$(D)"
	@if [ -n "$(OBJECTS)" ]; then \
		$(RM) $(OBJECTS); \
		printf "$(R)$(OBJECTS)\n$(D)"; \
	fi
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@if [ -n "$(OBJECTS)" ] || [ -n "$(PUSH_SWAP)" ]; then \
		$(RM) $(OBJECTS) $(PUSH_SWAP); \
		printf "$(B)\nForced cleaned $(D)"; \
		if [ -n "$(PUSH_SWAP)" ]; then \
			printf "$(Y)\n($(PUSH_SWAP))\n$(D)"; \
			$(RM) $(PUSH_SWAP); \
			printf "$(R)%s\n$(D)" "$(PUSH_SWAP)"; \
		fi; \
		printf "$(Y)\nSuccessfully cleaned$(D)\n"; \
	else \
		printf "$(Y)(Everything got cleaned)\n$(D)"; \
	fi
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re precomp
