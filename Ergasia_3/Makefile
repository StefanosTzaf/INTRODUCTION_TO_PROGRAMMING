# compiler
CC = gcc

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall
LDFLAGS = -lm

# Αρχεία .o
MemOBJS = lift.o liftmem.o
DynamicOBJS = lift.o liftdp.o
RecOBJS = lift.o liftrec.options


MemEXEC = liftmem
DynEXEC = liftdp
RecEXEC = liftrec

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =

$(MemEXEC): $(MemOBJS)
	$(CC) $(MemOBJS) -o $(MemEXEC) $(LDFLAGS)

$(DynEXEC): $(DynamicOBJS)
	$(CC) $(DynamicOBJS) -o $(DynEXEC) $(LDFLAGS)

$(RecEXEC): $(RecOBJS)
	$(CC) $(RecOBJS) -o $(RecEXEC) $(LDFLAGS)

clean:
	rm -f $(RecOBJS) $(DynamicOBJS) $(MemOBJS) $(MemEXEC) $(RecEXEC) $(DynEXEC)


runMem: $(MemEXEC)
	./$(MemEXEC) $(ARGS)

runDyn: $(DynEXECEXEC)
	./$(DynEXECEXEC) $(ARGS)

runRec: $(RecEXECEXEC)
	./$(RecEXEC) $(ARGS)


