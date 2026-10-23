
CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -Wpedantic
LDFLAGS  :=
LDLIBS   := 
TARGET   := main
OBJS     := main.o Stack.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

# Regras de compilação
%.o: %.c Stack.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
 