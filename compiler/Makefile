CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = oOcomp
SRCS = ./get_next_line.c \
	   ./get_next_line_utils.c \
	   ./print_file.c \
	   ./translate.c \
	   ./main.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		   $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
.c.o:
	 $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re:		fclean all
