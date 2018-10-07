#include <stdio.h>
#include <stdlib.h>

typedef struct Bloco{
	int expressao;
	struct Bloco* prox;
} Bloquinho;

typedef struct Node{
	Bloquinho* topo;
} No;

No* aloca_no(){
	No* n = (No*) malloc(sizeof(No));
	n->topo = NULL;
	return n;
}

Bloquinho* aloca_bloquinho(int valor){
	Bloquinho* b = (Bloquinho*) malloc(sizeof(Bloquinho));
	b->expressao = valor;
	b->prox = NULL;
	return b;
}

int esta_vazia(No* Node){
	return (Node->topo == NULL);
}

void push(char valor, No* Node){
	Bloquinho* b = aloca_bloquinho(valor);
	b->prox = Node->topo;
	Node->topo = b;
}

char pop(No* Node){
	if(esta_vazia(Node)){
		printf("Ocorreu underflow\n");
		return 0;
	}
	else{
		Bloquinho* temp;
		temp = Node->topo;
		char aux = temp->expressao;
		Node->topo = Node->topo->prox;
		free(temp);
		return aux;
	}
}


void print(No* Node){
	Bloquinho* b = Node->topo;
	while(b != NULL){
		printf("%d\n", b->expressao);
		b = b->prox;
	}
}

int main(){
	No* Node = aloca_no();
	push(7, Node);
	push(9, Node);
	push(10, Node);
	print(Node);
	printf("********\n");
	pop(Node);
	print(Node);
}