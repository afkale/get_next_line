LIBRARY				=	get_next_line.a
EXPORT				=	get_next_line.so

ifndef BUFFER_SIZE
	BUFFER_SIZE = 200000
endif

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
FLAGS_SANITIZE		=	-D BUFFER_SIZE=$(BUFFER_SIZE) -fsanitize=address
FLAGS_DEBUG			=	-D BUFFER_SIZE=$(BUFFER_SIZE) -g3

SRCS				=	./get_next_line.c ./get_next_line_utils.c
TESTFILE			=	tests.c

OBJS				=	$(SRCS:.c=.o)

all: $(LIBRARY)

debug: $(LIBRARY) $(TESTFILE)
	$(CC) $(FLAGS_DEBUG) -o debug $(TESTFILE) -L. -l:$(LIBRARY) -I .

sanitize: $(LIBRARY) $(TESTFILE)
	$(CC) $(FLAGS_SANITIZE) -o sanitize $(TESTFILE) -L. -l:$(LIBRARY) -I .

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) debug sanitize

re:	fclean all

#.SILENT: all $(LIBRARY) $(OBJS) clean fclean debug
.PHONY: all clean fclean re
