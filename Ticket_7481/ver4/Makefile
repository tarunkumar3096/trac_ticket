OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

out: $(OBJ)
	gcc $^ -o $@ -I.

%.o: %.c %.h
	gcc -c $< -o $@ -I.


.PHONY:clean

clean:
	rm *.o
	rm out
