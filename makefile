prog:enemi.o main.o 
	gcc enemi.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
enemi.o:enemi.c
	gcc -c enemi.c -g
