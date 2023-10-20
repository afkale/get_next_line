LIBRARY				=	get_next_line.a
EXPORT				=	get_next_line.so

ifndef BUFFER_SIZE
	BUFFER_SIZE = 200000
endif

CC					=	cc
CFLAGS				=	-g3 -Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
TESTFLAGS			=	-D BUFFER_SIZE=$(BUFFER_SIZE) -g3

SRCS				=	./get_next_line.c ./get_next_line_utils.c
TESTFILE			=	tests.c

OBJS				=	$(SRCS:.c=.o)

all: $(LIBRARY)

debug: $(LIBRARY)
	$(CC) $(TESTFLAGS) -o debug tests.c -L. -l:$(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) debug

re:	fclean all

#.SILENT: all $(LIBRARY) $(OBJS) clean fclean debug
.PHONY: all clean fclean re