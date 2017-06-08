#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Estruturas.h"

//Funções do TAD Lista alocada estáticamente

//Número desejado de discos = 0, iniciando a lista
void iniclista (TipoFila *Fila) {
	Fila->fim->discos = (EstruturaLista*) malloc (sizeof(EstruturaLista));
	Fila->fim->discos->numdesejado = 0;
}

//Desaloca lista depois de efetuar uma compra
void desalocalista (TipoFila *Fila) {
	free (Fila->inicio->discos);
}

//Verifica se a lista está vazia
int vazialista (TipoFila Fila) {
	return (Fila.fim->discos->numdesejado == 0);
}

//Inserir um desejo na lista
//Copia o valor para a lista e depois aumenta o numero desejado de vinils;
void inserelista (TipoFila *Fila, char *cantor, char *album, double valor) {
	if (Fila->fim->discos->numdesejado == LISTAMAX - 1)
		fprintf (stderr, "Sua lista de vinils desejados está cheia, remova um elemento\n"); 
	else {
		strcpy (Fila->fim->discos->cantor [Fila->fim->discos->numdesejado], cantor); //copia cantor para a lista
		strcpy (Fila->fim->discos->album [Fila->fim->discos->numdesejado], album); //copia album para a lista
		Fila->fim->discos->valor [Fila->fim->discos->numdesejado] = valor; //copia valor para a lista
		Fila->fim->discos->numdesejado ++; //aumenta o numero desejado de vinils
	}
}

//Remove um elemento da lista
//Copia os dados da posição final para a posição removida
//Diminui o numero de vinils desejados para -1
void removelista (TipoFila *Fila) {
	int pos;

	if (vazialista(*Fila)) 
		fprintf (stderr, "Sua lista de vinils está vazia\n");
	else {
		printf ("Digite a posição que você deseja remover\n");
		scanf ("%d", &pos);
		if (pos >= LISTAMAX) 
			fprintf (stderr, "Você digitou uma posição invalida\n");
		else {
			printf ("Removendo album %s do(s) %s, ", Fila->fim->discos->album[pos], Fila->fim->discos->cantor[pos]);
			printf(" o custo era %.2lf\n", Fila->fim->discos->valor[pos]);
			//Removendo cantor da posição e colocando cantor que estava na posição final
			strcpy (Fila->fim->discos->cantor[pos], Fila->fim->discos->cantor [Fila->fim->discos->numdesejado - 1]);
			//Removendo album da posição e colocando album que estava na posição final
			strcpy (Fila->fim->discos->album[pos], Fila->fim->discos->album [Fila->fim->discos->numdesejado - 1]);
			//Removendo valor da posição e colocando valor que estava na posição final	
			Fila->fim->discos->valor[pos] = Fila->fim->discos->valor [Fila->fim->discos->numdesejado - 1];
			Fila->fim->discos->numdesejado--; //diminuindo o numero de discos desejados 
		}
	}
}
		
//Calcula o valor total da compra do cliente
//Muda o valor da variavel valor, variavel que depois ira ser usada na pilha para armazenar o valor total da compra
void valorcompra (TipoFila Fila, double *valor) {
	int i;
	if (vaziafila (Fila)) {
	}
	else { 
	*valor = 0;
	for (i = 0; i < Fila.inicio->prox->discos->numdesejado; i++)
		*valor = Fila.inicio->prox->discos->valor[i] + *valor;
	printf ("O valor da compra foi de R$ %.2lf\n", *valor);
	}
}


//Impreme lista de desejos do cliente com o nome, album e valor, imprime apenas da ultima pessoa da fila, para alterações de inserir e remover desejos
void imprimelista (TipoFila Fila) {
	int i, num;
	
	if (vazialista(Fila))
		fprintf (stderr, "A Lista não pode ser imprimida, está vazia\n");
	else {
		printf ("Autor\tAlbum\tPreço\n");
		for (i=0; i < Fila.fim->discos->numdesejado; i++) {
			printf ("%d. ", i);
			printf ("%s\t", Fila.fim->discos->cantor[i]);
			printf ("%s\t", Fila.fim->discos->album[i]);
			printf ("%.2lf\n", Fila.fim->discos->valor[i]);
		}
	}
}
