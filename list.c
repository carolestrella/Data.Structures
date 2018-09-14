#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
	int codigo;
	char* nome;
	float preco;
	int quantidade;
} t_produto;

typedef struct elemento{
	t_produto* produto;
	struct elemento* proximo;
}t_elemento;

typedef struct lista{
	t_elemento* primeiro;
	t_elemento* ultimo;
}t_lista;


void inserir(int posicao, int codigo, char* nome, float preco, int quantidade, t_lista* lista);
void inserir_inicio(int codigo, char* nome, float preco, int quantidade, t_lista* lista);
void inserir_final(int codigo, char* nome, float preco, int quantidade, t_lista* lista);


t_produto* aloca_produto(int codigo, char* nome, float preco, int quantidade){
	t_produto* ptr = (t_produto*) malloc(sizeof(t_produto));
	ptr->codigo = codigo;
	ptr->preco = preco;
	ptr->quantidade = quantidade;
	ptr->nome = (char*) malloc(sizeof(char)*strlen(nome)+1);
	strcpy(ptr->nome,nome);
	return ptr;
}

t_elemento* aloca_elemento(int codigo, char* nome, float preco, int quantidade){
	t_elemento* ptr = (t_elemento*) malloc(sizeof(t_elemento));
	ptr->proximo = NULL;
	ptr->produto = aloca_produto(codigo, nome, preco, quantidade);
	return ptr;
}

t_lista* aloca_lista(){
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	return ptr;
}

int lista_vazia(t_lista* lista){ /* verifica se a lista esta vazia */
	return lista->primeiro == NULL;
}

void inserir(int posicao, int codigo, char* nome, float preco, int quantidade, t_lista* lista){ /* Insere na lista codigo, nome, preco e quantidade */
	int i;
	if(posicao < 0){
		printf("posicao invalida\n");
	}

	else if(posicao == 0 || lista_vazia(lista)){
		inserir_inicio(codigo, nome, preco, quantidade, lista);
	}
	else{
		t_elemento* atual = lista->primeiro;
		for(i = 0; i < (posicao-1) && (atual->proximo != NULL); i++){
			atual = atual->proximo;
		}
		if(i < posicao && atual == lista->ultimo){
			inserir_final(codigo, nome, preco, quantidade, lista);
		}
		else{
			t_elemento* elemento = aloca_elemento(codigo, nome, preco, quantidade);
			elemento->proximo = atual->proximo;
			atual->proximo = elemento;
		}
	}
}

void inserir_inicio(int codigo, char* nome, float preco, int quantidade, t_lista* lista){
	t_elemento* elemento = aloca_elemento(codigo, nome, preco, quantidade);
	elemento->proximo = lista-> primeiro;
	lista->primeiro = elemento;
	if(lista->ultimo == NULL)
		lista->ultimo = lista->primeiro;
}

void inserir_final(int codigo, char* nome, float preco, int quantidade, t_lista* lista){
	t_elemento* elemento = aloca_elemento(codigo, nome, preco, quantidade);
	if(lista->primeiro == NULL && lista->ultimo == NULL)
		lista->primeiro = elemento;
	else
		lista->ultimo->proximo = elemento;
	lista->ultimo = elemento;
}

void remove_lista(t_lista* lista){ /* remove elementos da lista e memoria alocada de forma dinamica */
	if(lista != NULL){
		t_elemento* elemento;
		t_produto* produto;
		for(elemento = lista->primeiro; lista->primeiro; elemento = lista->primeiro){
			free(elemento->produto->nome);
			free(elemento->produto);
			lista->primeiro = elemento->proximo;
			free(elemento);
		}
		free(lista);
	}
}

void print(t_lista* lista){ /* imprime na tela exemplo da funcionalidade do programa */
	t_produto* produto;
	if(lista->primeiro == NULL)
		printf("Lista vazia\n");
	else{
		t_elemento* temp = lista->primeiro;
		while(temp != NULL){
			printf(" %d %s %.1f %d\n", temp->produto->codigo, temp->produto->nome, temp->produto->preco, temp->produto->quantidade);
			printf("******************************\n");
			temp = temp->proximo;
		}
		printf("\n");
	}
}


int main(){

	t_lista* lista = aloca_lista();
	/*exemplo de utilizacao do programa */
	inserir(0, 101, "agua", 5.00, 6, lista);
	inserir(0, 143, "macarrao", 15.50, 4, lista);
	inserir(5, 322, "iogurte", 4.50, 5, lista);
	inserir(6, 22, "limao", 3.00, 100, lista);
	inserir(1, 14, "cha", 13.50, 50, lista);
	print(lista);
	/* fim do exemplo */
	remove_lista(lista);
}
