CXXFLAGS = -Wall -g
EXEC = main
OBJS = Microcontroller.o R500.o PIC32F42.o Micro34HC22.o

.PHONY: all
all: $(EXEC)

main: main.cpp $(OBJS)

Microcontroller.o : Microcontroller.h
R500.o : R500.h
PIC32F42.o : PIC32F42.h
Micro34HC22.o : Micro34HC22.h

.PHONY: clean
clean:
	$(RM) *.o *~ core a.out main $(EXEC)
