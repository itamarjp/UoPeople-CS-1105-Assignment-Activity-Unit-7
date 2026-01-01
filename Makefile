NAME=stack

all: $(NAME).o
	ld -o $(NAME) $(NAME).o
	rm -f *.o

%.o: %.asm
	nasm -g -f elf64 $<
