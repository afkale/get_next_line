LIBRARY				=	get_next_line.a
EXPORT				=	get_next_line.so

ifndef BUFFER_SIZE
	BUFFER_SIZE = 200000
endif

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
TESTFLAGS			=	-D BUFFER_SIZE=$(BUFFER_SIZE) -g3 -fsanitize=address

SRCS				=	./get_next_line.c ./get_next_line_utils.c
TESTFILE			=	tests.c

OBJS				=	$(SRCS:.c=.o)

all: $(LIBRARY)

test: $(TESTFILE) $(LIBRARY)
	$(CC) $(TESTFLAGS) -g3 -o $@ $< -L. -l:$(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) test

re:	fclean all 

.SILENT: all $(LIBRARY) $(OBJS) clean fclean test
.PHONY: all clean fclean re