#include <stdio.h>
#include <string.h>
#include "Estruturas.h"

void intrucoesLista () {
	printf ("1 - Adicionar Vinil\n");
	printf ("2 - Remover Vinil\n");
	printf ("3 - Imprimir Lista de Vinils\n");
	printf ("4 - Sair\n"); 
}

void intrucoesMenu () {
	printf ("0 - Novo Cliente na Fila (Enfileira)\n");
	printf ("1 - Cliente Efetua Compra (Desenfileira)\n");
	printf ("2 - Imprime Fila de Clientes\n");
	printf ("3 - Imprime Pilha de Recibos\n");
	printf ("4 - Imprime Pilha de Recibos Invertidas\n");
}

main () {
	TipoFila Fila;
	TipoPilha Pilha;
	char cliente[CHARMAX], cantor[CHARMAX], album[CHARMAX];
	int ComandoF, ComandoL;
	double valor; 

	inicfila (&Fila);
	inicpilha (&Pilha);
	for (;;) {
		intrucoesMenu();
		scanf ("%d", &ComandoF);
		switch (ComandoF) {
			case 0: 
			printf ("Entre com o nome do cliente\n");
			scanf ("%s", cliente);
			enfileira (&Fila, cliente);
			iniclista (&Fila);
			intrucoesLista();
			scanf ("%d", &ComandoL);
				while (ComandoL != 4) {
					switch (ComandoL) {
						case 1:
							printf ("Entre com o nome do cantor\n");
							scanf ("%s", cantor);
							printf ("Entre com o nome do album\n");
							scanf ("%s", album);
							printf ("Entre com o valor do vinil\n");
							scanf ("%lf", &valor);
							inserelista (&Fila, cantor, album, valor);
							break;
						case 2:
							removelista (&Fila);
							break;
						case 3:
							imprimelista (Fila);
							break;
						} //fim switch
					intrucoesLista ();
					scanf ("%d", &ComandoL);
				} //fim while
			break; //Break do case 0
			case 1: 
			valorcompra(Fila, &valor);
			desalocalista (&Fila);
			desenfileira (&Fila, cliente);
			push (&Pilha, cliente, valor); 
			break;
			case 2:
			imprimefila (Fila);
			break;
			case 3:
			imprimepilha (Pilha);
			break;
			case 4:
			invertepilha (&Pilha);
			imprimepilha (Pilha);
                }
	}
}
