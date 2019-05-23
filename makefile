all: yuv2rgb

yuv2rgb: main.o bmp_utils.o yuv2rgb.o
	gcc $^ -o $@

main.o: main.cpp
	g++ $< -c -o $@

%.o: %.c
	gcc $< -c -o $@

clean:
	rm *.o yuv2rgb

test: bmp_utils.c test.c
	gcc $^ -o $@

gen:
	make -C fill_yuv
