CC=cc
CFLAGS=-c
LDFLAGS=
SOURCES=functions.c matrix.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=matrix

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@