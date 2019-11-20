compilar:
	nasm -f elf 09-01-lfsr.asm
	gcc -o lfsr 09-01-lfsr.c 09-01-lfsr.o -m32 -lm

clean: 
	rm -f lfsr *.o