NAME				=	get_next_line.a
EXPORT				=	get_next_line.so
CC					=	gcc
AR					=	ar
RM					=	rm -f
CFLAGS				=	-g -Wall -Werror -Wextra -D BUFFER_SIZE=42 .
SRCS				=	./get_next_line.c ./get_next_line_utils.c
OBJS				=	$(SRCS:.c=.o)
BONUS_OBJS			=	$(BONUS_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

export: $(OBJS)
	$(CC) $(CFLAGS) -shared -o $(EXPORT) $(OBJS)

re:	fclean $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	$(AR) rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.SILENT: all $(NAME) $(OBJS) clean fclean re bonus export
.PHONY: all clean fclean re bonus
