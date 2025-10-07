objects = main.o
CC = gcc

bin: $(objects)
	$(CC) $^ -o bin

$(objects): %.o: %.c
	$(CC) -c $^ -o $@ -g

clean:
	rm -f *.o bin 