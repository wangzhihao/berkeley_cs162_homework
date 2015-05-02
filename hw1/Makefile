SRCS=main.c shell.c process.c io.c parse.c 
EXECUTABLES=shell 

CC=gcc
CFLAGS=-g -Wall 
LDFLAGS=

#	See https://www.gnu.org/software/make/manual/make.html#Substitution-Refs
OBJS=$(SRCS:.c=.o)

all: $(EXECUTABLES)

$(EXECUTABLES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@  

# 
# See https://www.gnu.org/software/make/manual/make.html#Suffix-Rules
# We can rewrite it into a pattern rule as such:
# 	%.o : %.c
#			$(CC) $(CFLAGS) -c $< -o $@
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXECUTABLES) $(OBJS)
