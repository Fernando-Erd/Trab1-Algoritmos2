all: 
	gcc -c Fila.c 
	gcc -c FilaAuxiliar.c 
	gcc -c Lista.c 
	gcc -c Pilha.c 
	gcc -c main.c
	gcc Fila.o FilaAuxiliar.o Lista.o Pilha.o main.o -o Kidvinil -g
	rm *.o
