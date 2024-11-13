# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:54:52 by chorst            #+#    #+#              #
#    Updated: 2024/04/18 09:51:14 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libget_next_line.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar -rcs

# Define Colours
R := \033[0;31m
G := \033[0;32m
Y := \033[0;93m
D := \033[0m

SRC	= get_next_line_utils.c get_next_line.c

all: precomp $(NAME)

 $(NAME):	$(SRC:.c=.o)
	@$(AR) $(NAME) $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@printf "$(G)$(notdir $<)$(D)\n"

clean:
	@printf "\n$(Y)(get_next_line.o)\n$(D)"
	@for file in $(SRC:.c=.o); do \
		$(RM) $$file; \
		printf "$(R)%s\n$(D)" "$$file"; \
	done

fclean:
	@if ls *.o 1> /dev/null 2>&1; then \
		printf "$(Y)\n(get_next_line.o)\n$(D)"; \
		for file in $(SRC:.c=.o); do \
			$(RM) $$file; \
			printf "$(R)%s\n$(D)" "$$file"; \
		done; \
		printf "$(Y)(get_next_line.a)\n$(D)"; \
		printf "$(R)%s\n$(D)" "$(NAME)"; \
		$(RM) $(NAME); \
	elif ls libget_next_line.a 1> /dev/null 2>&1; then \
		printf "$(Y)\n(get_next_line.a)\n$(D)"; \
		printf "$(R)%s\n$(D)" "$(NAME)"; \
		$(RM) $(NAME); \
	fi

re: clean all

precomp:
	@printf "$(Y)\n(get_next_line)\n"
