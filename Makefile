CC = g++
CFLAGS= #-O2
LIBS = -lm #-lGLEW
SRC= main.cpp vector.cpp raytracer.cpp ray.cpp \
	sphere.cpp light.cpp object.cpp 
OUTPUT=out

OBJ=$(SRC:.cpp=.o)

CFLAGS+=-g
DBGFLAGS = #-D_FPVIEW -D_ANIM #-D_DBG

ifeq ($(shell uname),Darwin)
	LIBS+= -framework OpenGL -framework GLUT
else
	LIBS+= -lglut -lGLU
endif

all: gs

clean:
	rm $(OBJ)
	rm $(OUTPUT)

gs: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(DBGFLAGS) -o $(OUTPUT) $^

.cpp.o:
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

depend:
	makedepend -- $(CFLAGS) -- $(SRC)
# DO NOT DELETE
