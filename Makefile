# define C compiler & flags
CC = gcc
CFLAGS = -Wall -g
# define libraries to be linked (for example -lm)
LDLIBS = 

# define sets of header source files and object files
SRC = main.c data.c list.c 
# OBJ is the same as SRC, just replace .c with .h
OBJ = $(SRC:.c=.o)
 
# define the executable name(s)
EXE = dict1

# the first target:
dict1: $(OBJ) 
	$(CC) $(CFLAGS) -o dict1 $(OBJ) $(LDLIBS)

# define the executable name(s)
EXE = dict2

# the first target:
dict2: $(OBJ) 
	$(CC) $(CFLAGS) -o dict2 $(OBJ) $(LDLIBS)


clean:
	rm -f $(OBJ) $(EXE)
