#include <stdio.h>
#include <stdlib.h>

typedef struct Bloco{
	int data;
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
	b->data = valor;
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

void pop(No* Node){
	if(esta_vazia(Node)){
		printf("Ocorreu underflow\n");
	}
	else{
		Bloquinho* temp;
		temp = Node->topo;
		char aux = temp->data;
		Node->topo = Node->topo->prox;
		free(temp);
	}
}

int top(No* Node){
	return Node->topo->data;
}


void print(No* Node){
	Bloquinho* b = Node->topo;
	while(b != NULL){
		printf("%d\n", b->data);
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
