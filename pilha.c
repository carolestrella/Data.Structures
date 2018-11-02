/**
*@file pilha.c
*@author Carolina Estrella Machado
*@date 19 october 2018
*@brief implementacao das funcoes contidas no arquivo pilha.h
*/

#include "pilha.h"
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*@brief a funcao aloca_no faz um malloc do tipo No e inicializa o topo como NULL
*@return n
*/

No* aloca_no(){
	No* n = (No*) malloc(sizeof(No));
	n->topo = NULL;
	return n;
}

/**
*@brief a funcao aloca_bloquinho cria um elemento do tipo char e coloca na pilha
*@return b
*/

Bloquinho* aloca_bloquinho(char valor){
	Bloquinho* b = (Bloquinho*) malloc(sizeof(Bloquinho));
	b->expressao = valor;
	b->prox = NULL;
	return b;
}

/**
*@brief a funcao aloca_pilha faz um malloc do tipo pilha e inicializa o topo como NULL
*@return p
*/

pilha* aloca_pilha(){
	pilha* p = (pilha*) malloc(sizeof(pilha));
	p->topo = NULL;
	return p;
}

/**
*@brief a funcao aloca_elemento cria um elemento do tipo double e coloca na pilha
*@return e
*/

elemento* aloca_elemento(double valor){
	elemento* e = (elemento*) malloc(sizeof(elemento));
	e->valor = valor;
	e->prox = NULL;
	return e;
}

/**
*@brief a funcao esta_vazia retorna true se a pilha tipo char estiver vazia e false caso contrario
*@param Node
*@return bool
*/

int esta_vazia(No* Node){
	return (Node->topo == NULL);
}

/**
*@brief a funcao esta_vazia retorna true se a pilha tipo double estiver vazia e false caso contrario
*@param Pilha
*@return bool
*/

int esta_vaziadouble(pilha* Pilha){
	return (Pilha->topo == NULL);
}

/**
*@brief a funcao push impilha um char na pilha
*@param1 valor @param2 Node
*@return @c void
*/

void push(char valor, No* Node){
	Bloquinho* b = aloca_bloquinho(valor);
	b->prox = Node->topo;
	Node->topo = b;
}

/**
*@brief a funcao pushdouble impilha um double na pilha
*@param1 valor @param2 Pilha
*@return @c void
*/

void pushdouble(double valor, pilha* Pilha){
	elemento* e = aloca_elemento(valor);
	e->prox = Pilha->topo;
	Pilha->topo = e;
}

/**
*@brief a funcao pop desempilha um char da pilha
*@param Node
*@return void
*/

void pop(No* Node){
	if(esta_vazia(Node)){
		printf("Ocorreu underflow\n");
	}
	else{
		Bloquinho* temp;
		temp = Node->topo;
		Node->topo = Node->topo->prox;
		free(temp);
	}
}

/**
*@brief a funcao popdouble desempilha um double da pilha
*@param Pilha
*@return void
*/

void popdouble(pilha* Pilha){
	if(esta_vaziadouble(Pilha)){
		printf("Ocorreu underflow\n");
	}
	else{
		elemento* temp;
		temp = Pilha->topo;
		Pilha->topo = Pilha->topo->prox;
		free(temp);
	}
}

/**
*@brief a funcao top retorna o elemento tipo char do topo
*@param Node
*@return Node->topo->expressao
*/

char top(No* Node){
	return Node->topo->expressao;
}

/**
*@brief a funcao topdouble retorna o elemento tipo double do topo
*@param Pilha
*@return Pilha->topo->valor
*/

double topdouble(pilha* Pilha){
	return Pilha->topo->valor;
}

/**
*@brief a funcao libera_pilha desempilha e libera os ponteiros alocados
*@param Node
*@return void
*/

void libera_pilha(No* Node){
	Bloquinho* b;
	b = Node->topo;
	while(b != NULL){
		Node->topo = b->prox;
		free(b);
		b = Node->topo;
	}
	free(Node);
}

/**
*@brief a funcao libera_pilhadouble desempilha e libera os ponteiros alocados
*@param Pilha
*@return void
*/

void libera_pilhadouble(pilha* Pilha){
	elemento* e;
	e = Pilha->topo;
	while(e != NULL){
		Pilha->topo = e->prox;
		free(e);
		e = Pilha->topo;
	}
	free(Pilha);
}

/**
*@brief a funcao print imprime na tela a pilha tipo char
*@param Node
*@return void
*/

void print(No* Node){
	Bloquinho* b = Node->topo;
	while(b != NULL){
		printf("%d\n", b->expressao);
		b = b->prox;
	}
}

/**
*@brief a funcao printdouble imprime na tela a pilha tipo double
*@param Pilha
*@return void
*/

void printdouble(pilha* Pilha){
	elemento* e = Pilha->topo;
	int i=1;
	if(Pilha->topo == NULL){
		printf("Pilha Vazia!\n\n");
	}
	else{
		while(e != NULL){
			printf("%d. %.2lf\n", i, e->valor);
			e = e->prox;
			i++;
		}
		printf("\n");
	}
}
