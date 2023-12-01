# Makefile for cppratio project

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall -Wextra

# Executables
TARGETONE = RatioExample
TARGETTWO = RatioExample2

all:	$(TARGETONE) $(TARGETTWO)

# Build targets
$(TARGETONE): Ratio.o RatioExample.o
	$(CC) $(CFLAGS) Ratio.o RatioExample.o -o $(TARGETONE)

$(TARGETTWO): Ratio.o RatioExample2.o
	$(CC) $(CFLAGS) Ratio.o RatioExample2.o -o $(TARGETTWO)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f *.o $(TARGETONE) $(TARGETTWO)

