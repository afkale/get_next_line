NAME				=	get_next_line.a
EXPORT				=	get_next_line.so

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -D BUFFER_SIZE=200000

SRCS				=	./get_next_line.c ./get_next_line_utils.c

OBJS				=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all 
