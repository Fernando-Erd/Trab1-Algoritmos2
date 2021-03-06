#define LISTAMAX 5
#define CHARMAX 50

typedef struct {
	char cantor[LISTAMAX][CHARMAX]; //cantor do disco
	char album[LISTAMAX][CHARMAX]; //album do disco
	double valor [LISTAMAX]; //preço do disco
	int numdesejado; //Ira armazenar a quantidade de discos que o cliente quer
} EstruturaLista;
	

typedef struct EstruturaFila {
	char cliente[CHARMAX]; //nome do cliente
	EstruturaLista *discos; //apontador para a lista estática
	struct EstruturaFila *prox; //apontador para a proxima fila
} EstruturaFila;

typedef struct EstruturaPilha {
	char cliente[CHARMAX]; //nome do cliente
	double valor; //valor total da compra do cliente
	struct EstruturaPilha *prox; //apontador para a proxima pilha
} EstruturaPilha;



typedef struct {
	EstruturaFila *inicio, *fim; //apontadores para a fila
} TipoFila;

typedef struct {
	EstruturaPilha *topo; //apontador para a pilha
	int numelementos;
} TipoPilha;

typedef struct EstruturaFilaAux {
	char cliente[CHARMAX]; //nome do cliente
	double valor; //valor total da compra do cliente
	struct EstruturaFilaAux *prox; //apontador para a proxima pilha
} EstruturaFilaAux; 


typedef struct {
	EstruturaFilaAux *inicio, *fim; //apontadores para a fila auxiliar
} TipoFilaAux;
