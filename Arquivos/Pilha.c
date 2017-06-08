#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Estruturas.h"

void inicpilha (TipoPilha *Pilha) {
	Pilha->topo = (EstruturaPilha*)malloc(sizeof(EstruturaPilha));
	Pilha->numelementos = 0;
	Pilha->topo->prox = NULL;
}

int vaziapilha (TipoPilha Pilha) {
	return (Pilha.numelementos == 0);
}

//Empilhar
void push (TipoPilha *Pilha, char cliente[CHARMAX], double valor) {
	EstruturaPilha *aux;
	
	aux = (EstruturaPilha*)malloc(sizeof(EstruturaPilha));
	aux->prox = Pilha->topo;
	strcpy (Pilha->topo->cliente, cliente);
	Pilha->topo->valor = valor;
	Pilha->topo = aux;
	Pilha->numelementos++;
}

//Desempilha
//Muda a variavel cliente, para que o nome cliente seja armazenado na pilha
void pop (TipoPilha *Pilha, char *cliente, double *valor) {
	EstruturaPilha *aux;

	if (vaziapilha(*Pilha))
		fprintf (stderr, "A pilha de recibos está vazia\n");
	else {
		aux = Pilha->topo;
		Pilha->topo = aux->prox;
		free (aux);
		strcpy (cliente, Pilha->topo->cliente);
		*valor = Pilha->topo->valor;
		Pilha->numelementos--;
	}
}

//Imprime Pilha
void imprimepilha (TipoPilha Pilha) {
	EstruturaPilha *aux;

	if (vaziapilha (Pilha))
		fprintf (stderr, "A Pilha de Recibos está vazia, ninguém comprou na loja ainda\n");
	aux = Pilha.topo->prox;
	while (Pilha.numelementos != 0) {
		printf ("Cliente: %s, gastou R$ %.2lf\n", aux->cliente, aux->valor);
		aux = aux->prox;
		Pilha.numelementos--;
	}
}

void invertepilha (TipoPilha *Pilha) {
	TipoFilaAux FilaAux;
	char cliente[CHARMAX];
	double valor;
	
	inicfilaAUX (&FilaAux);
	while (!vaziapilha(*Pilha)) {
		valor = 0;
		pop (Pilha, cliente, &valor);
		enfileiraAUX (&FilaAux, cliente, valor);
	}
	while (!vaziafilaAUX(FilaAux)) {
		valor = 0;
		desenfileiraAUX (&FilaAux, cliente, &valor);
		push (Pilha, cliente, valor);
	}
}
