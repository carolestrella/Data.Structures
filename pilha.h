/**
*@file pilha.h
*@author Carolina Estrella Machado
*@date 19 october 2018
*@brief assinaturas das funcoes que serao implementadas no arquivo pilha.c
*/

#ifndef __PILHA_H__
#define __PILHA_H__

/**
*@brief estrutura do elemento tipo char que sera alocado na pilha
*/

typedef struct Bloco{
	char expressao;
	struct Bloco* prox;
} Bloquinho;

/**
*@brief estrutura de ponteiro para o topo da pilha
*/

typedef struct Node{
	Bloquinho* topo;
} No;

/**
*@brief estrutura do elemento tipo double que sera alocado na pilha
*/

typedef struct Elemento{
	double valor;
	struct Elemento* prox;
} elemento;

/**
*@brief estrutura de ponteiro para o topo da pilha
*/

typedef struct Pilha{
	elemento* topo;
} pilha;

/**
*@brief a funcao aloca_no aloca um ponteiro para o topo da pilha
*/

No* aloca_no();

/**
*@brief a funcao aloca_bloquinho aloca um novo elemento tipo char na pilha
*/

Bloquinho* aloca_bloquinho(char valor);

/**
*@brief a funcao aloca_pilha aloca um ponteiro para o topo da pilha tipo double
*/

pilha* aloca_pilha();

/**
*@brief a funcao aloca_elemento aloca um novo elemento tipo double na pilha
*/

elemento* aloca_elemento(double valor);

/**
*@brief a funcao esta_vazia verifica se o topo == NULL
*/

int esta_vazia(No* Node);

/**
*@brief a funcao esta_vaziadouble verifica se o topo == NULL
*/

int esta_vaziadouble(pilha* Pilha);

/**
*@brief a funcao push impilha um novo elemento do tipo char na pilha
*/

void push(char valor, No* Node);

/**
*@brief a funcao pushdouble impilha um novo elemento do tipo double na pilha
*/

void pushdouble(double valor, pilha* Pilha);

/**
*@brief a funcao pop desempilha um elemento do tipo char da pilha
*/

void pop(No* Node);

/**
*@brief a funcao popdouble desempilha um elemento do tipo double da pilha
*/

void popdouble(pilha* Pilha);

/**
*@brief a funcao top retorna o elemento tipo char que esta no topo da pilha
*/

char top(No* Node);


/**
*@brief a funcao topdouble retorna o elemento tipo double que esta no topo da pilha
*/

double topdouble(pilha* Pilha);


/**
*@brief a funcao libera_pilha desempilha e libera os ponteiros alocados
*/

void libera_pilha(No* Node);

/**
*@brief a funcao libera_pilhadouble desempilha e libera os ponteiros alocados
*/

void libera_pilhadouble(pilha* Pilha);

/**
*@brief a funcao print imprime na tela a pilha tipo char
*/

void print(No* Node);

/**
*@brief a funcao print imprime na tela a pilha tipo double
*/

void printdouble(pilha* Pilha);

#endif
