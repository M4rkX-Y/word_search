OBJS = heap.o dictionary.o grid.o main.o

all: $(OBJS)
	g++ -o main $(OBJS)

%o: %.cpp %.h
	g++ -c $<

.PHONY: clean

clean:
	rm -f *.o main