NAME = minishell

INC = include 

SRCS =	srcs/utils.c \
		srcs/lexer2.c \
		srcs/list.c


OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -g3 -Wall -Wextra

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lreadline -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all