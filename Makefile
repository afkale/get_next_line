LIBRARY				=	get_next_line.a
EXPORT				=	get_next_line.so

ifndef BUFFER_SIZE
	BUFFER_SIZE=10000000
endif

CC					=	gcc
CFLAGS				=	-g3 -Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
FLAGS_SANITIZE		=	-D BUFFER_SIZE=$(BUFFER_SIZE) -fsanitize=address
FLAGS_DEBUG			=	-D BUFFER_SIZE=$(BUFFER_SIZE) -g3

SRCS				=	./get_next_line.c ./get_next_line_utils.c
TESTFILE			=	tests.c

OBJS				=	$(SRCS:.c=.o)

B_SRCS				=	./get_next_line_bonus.c ./get_next_line_utils_bonus.c
B_OBJS				=	$(B_SRCS:.c=.o)

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

bonus: $(B_OBJS)
	touch bonus
	$(AR) rcs get_next_line_bonus.a $(B_OBJS) 
	
bdebug: get_next_line_bonus.a $(TESTFILE)
	$(CC) $(FLAGS_DEBUG) -o bdebug $(TESTFILE) -L. -l:get_next_line_bonus.a -I .

debug: $(LIBRARY) $(TESTFILE)
	$(CC) $(FLAGS_DEBUG) -o debug $(TESTFILE) -L. -l:$(LIBRARY) -I .

bsanitize: get_next_line_bonus.a $(TESTFILE) 
	$(CC) $(FLAGS_SANITIZE) -o bsanitize $(TESTFILE) -L. -l:get_next_line_bonus.a -I .

sanitize: $(LIBRARY) $(TESTFILE) 
	$(CC) $(FLAGS_SANITIZE) -o sanitize $(TESTFILE) -L. -l:$(LIBRARY) -I .

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(LIBRARY) debug sanitize bdebug bsanitize

re:	fclean all

#.SILENT: all $(LIBRARY) $(OBJS) clean fclean debug sanitize
.PHONY: all clean fclean re 
