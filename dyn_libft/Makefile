CC = gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC_C = ft_memcpy.c ft_memset.c \
		dynarray.c dynarray2.c

INC_H = libft.h dynarray.h

OBJS = $(SRC_C:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$%.o: $%.c $(INC_H)
	$(CC) $(CFLAGS) -c $< -o $@
