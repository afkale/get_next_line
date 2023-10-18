LIBRARY				=	get_next_line.a
EXPORT				=	get_next_line.so

ifndef BUFFER_SIZE
	BUFFER_SIZE = 200000
endif

CC				=	cc
CFLAGS				=	-Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
SRCS				=	./get_next_line.c ./get_next_line_utils.c
TESTFILE			=	main.c

OBJS				=	$(SRCS:.c=.o)

all: $(LIBRARY)
	@echo "Gud bro..."

test: $(TESTFILE) $(LIBRARY)
	$(CC) $(CFLAGS) -g3 -o $@ $< -L. -l:$(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) test

re:	fclean all 

.SILENT: all LIBRARY $(OBJS) clean fclean
.PHONY: all clean fclean re