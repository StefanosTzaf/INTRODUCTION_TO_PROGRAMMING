
CC = gcc

CFLAGS = -Wall  -g


OBJS = mertsumd.o

EXEC = mertsumd

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

time: $(EXEC)
	/usr/bin/time -f "Execution time: %U seconds! " ./$(EXEC) $(ARGS)