NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	push_swap.c check.c cost.c index_target_position.c\
		moves.c push.c reverse_rotate.c rotate.c\
		swap.c sort_three.c sort_more.c utils.c utils_2.c\
	
OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all bonus 

.PHONY: re all bonus clean fclean