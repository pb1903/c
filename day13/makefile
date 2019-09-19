cc=gcc
target=demo
obj=main.o fun.o start_mplayer.o console.o

$(target):$(obj)
	$(cc) $^ -o $@ 
%.o:%.c
	$(cc) -c $< -o $@ 

clean:
	rm $(target) $(obj)