# compiler
CC = gcc

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall  -g -I$(INCLUDE)
LDFLAGS = -lm

# Αρχεία .o

#για να ελεγθει η δευτερη υλοποιηση ξεσχολιαζουμε την παρακατω γραμμη και σχολιαζουμε την επομενη της
MemOBJS = lift.o liftmem.o
DynamicOBJS = lift.o liftdp.o
RecOBJS = lift.o liftrec.options

MemEXEC = liftmem
DynEXEC = liftdp
RecEXEC = liftrec

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =

include /../../common.mk
