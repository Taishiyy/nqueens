NAME = nqueens
INCLUDE = nqueens.h

SRCS = nqueens.c
	   
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE) -g -O0
RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re