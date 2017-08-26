all: copy whodunit

copy: copy.c bmp.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o copy copy.c -lcs50 -lm

whodunit: whodunit.c bmp.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o whodunit whodunit.c

clean:
	rm -f *.o a.out copy whodunit
