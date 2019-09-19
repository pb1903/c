cc=gcc
target=demo
obj=00_main.o fun.o
cflags=-Wall -std=c99

$(target):$(obj)
	$(cc) $^ -o $@ $(cflags)
%.o:%.c
	$(cc) -c $< -o $@ $(cflags)

clean:
	rm $(target) $(obj)