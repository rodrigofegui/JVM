compilar:
	nasm -f elf lfsr.asm
	gcc -o lfsr driver_lfsr.c lfsr.o -m32 -lm

clean: 
	rm -f lfsr *.o