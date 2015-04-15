check: clean
	gcc main.c -o main.o
	gcc map.c -o map.o
	gcc wc.c -o wc.o
debug_wc: clean
	gcc -g wc.c -o wc.o
	gcc -g additional/wc_official.c -o wc_official.o
clean:
	rm -rf *o *out
