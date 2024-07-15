# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/15 21:57:06 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CC		=	cc -g -fsanitize=address

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

NAME	=	push_swap
P_LIB	=	push_swap.a
DIR		=	lib
LIB		=	libft.a

EXE_PATH=	.
# EXE_PATH=	./bin

TEST	=	./src/main.c

SRCS	=	./src/main.c ./src/parsing.c ./src/error_checks.c ./src/list_fns.c \
			./src/op_push.c ./src/op_swap.c ./src/op_rotate.c ./src/op_rev_rotate.c \
			./src/index.c ./src/sorting.c ./src/algorithm.c ./src/utils.c

OBJS	=	$(SRCS:.c=.o)

# DEBUG	=	$(TEST)
DEBUG	=	$(SRCS)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	cp ./$(DIR)/$(LIB) ./$(P_LIB)
	ar rcs $(P_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(P_LIB) -o $(EXE_PATH)/$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -sC $(DIR) all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(P_LIB)
	$(RM) $(EXE_PATH)/$(NAME)
	$(RM) $(EXE_PATH)/$(NAME)2
	$(RM) ./bin/test
	$(RM) -r ./bin/test.dSYM
	$(RM) ./bin/bug
	$(RM) -r ./bin/bug.dSYM

re: fcleanx
	$(MAKE) fclean
	$(MAKE) all

cleanx:
	$(RM) $(OBJS)
	$(MAKE) -sC $(DIR) clean

fcleanx: cleanx
	$(RM) $(P_LIB)
	$(RM) $(EXE_PATH)/$(NAME)
	$(MAKE) -sC $(DIR) fclean

bug:
	$(CC) -g $(CFLAGS) ./$(DIR)/$(LIB) $(DEBUG) -o ./bin/bug

test:
	$(CC) $(CFLAGS) ./$(DIR)/$(LIB) $(TEST) -o ./bin/test
	./bin/test
	

.PHONY: all clean fclean re cleanx fcleanx bug test
