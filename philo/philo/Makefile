NAME = philo

SRCS = $(shell find . -name "*.c")

CC = gcc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror #-fsanitize=thread
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)


clean : 
	$(RM) $(OBJS)
fclean : clean
		$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean res