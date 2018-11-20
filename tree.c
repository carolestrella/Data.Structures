#include <stdio.h>
#include <stdlib.h>


///////////////////////////ARVORE//////////////////////////////////

typedef struct t_no{ 
	int dado;
	struct t_no* esq;
	struct t_no* dir; 
} tipoNo;

tipoNo* criaRaiz(int dado){
	tipoNo* ptr = (tipoNo*)malloc(sizeof(tipoNo));
	ptr->esq = NULL;
	ptr->dir = NULL;
	ptr->dado = dado;

	return ptr;
}

tipoNo* inserirNo(tipoNo* raiz, int dado){
	if(raiz == NULL)
		return criaRaiz(dado);

	if(dado < raiz->dado)
		raiz->esq = inserirNo(raiz->esq, dado);
	else if(dado > raiz->dado)
		raiz->dir = inserirNo(raiz->dir, dado);

	return raiz;
}

tipoNo* buscaNo(tipoNo* raiz, int dado){
	tipoNo* aux;
	if(raiz == NULL)
		return NULL;
	else if(raiz->dado == dado)
		return raiz;
	else{
		aux = buscaNo(raiz->esq, dado);
		if(aux == NULL)
			aux = buscaNo(raiz->dir, dado);
		return aux;
	}
	return NULL;
}

void pre_ordem(tipoNo* raiz){
	if(raiz != NULL){
		printf("%d ", raiz->dado);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void em_ordem(tipoNo* raiz){
	if(raiz != NULL){
		em_ordem(raiz->esq);
		printf("%d ", raiz->dado);
		em_ordem(raiz->dir);
	}
}

void pos_ordem(tipoNo* raiz){
	if(raiz != NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->dado);
	}
}

////////////////////////////FILA////////////////////////////////////

typedef struct elemento{
	tipoNo* dado;
	struct elemento* prox;
}t_elemento;

typedef struct{
	t_elemento* prim;
	t_elemento* ult;
}t_fila;

t_fila* aloca_fila(){
	t_fila* ptr = (t_fila*)malloc(sizeof(t_fila));
	ptr->prim = NULL;
	ptr->ult = NULL;
	return ptr;
}

t_elemento* aloca_elemento(tipoNo* dado){
	t_elemento* ptr = (t_elemento*)malloc(sizeof(t_elemento));
	ptr->prox = NULL;
	ptr->dado = dado;
	return ptr;
}

void inserir(tipoNo* dado, t_fila* fila){
	t_elemento* ptr = aloca_elemento(dado);
	if(fila->prim == NULL && fila->ult == NULL)
		fila->prim = ptr;
	else
		fila->ult->prox = ptr;
	fila->ult = ptr;
}

int filavazia(t_fila* fila){
	return (fila->prim == NULL && fila->ult == NULL);
}

tipoNo* remover(t_fila* fila){
	if(filavazia(fila)){
		free(fila);
		exit(0);
	}
	t_elemento* ptr = fila->prim;
	tipoNo* result;
	result = ptr->dado;
	if(fila->prim == fila->ult)
		fila->ult = NULL;
	fila->prim = fila->prim->prox;
	free(ptr);
	return result;
}


/////////////////////////////////////////////////////////////////

void percurso_largura(tipoNo* raiz){
	t_fila* fila = aloca_fila();
	tipoNo* no = NULL;
	if(raiz == NULL)
		return;
	inserir(raiz, fila);
	while(!filavazia(fila)){
		no = remover(fila);
		printf("%d ", no->dado);
		if(no->esq != NULL)
			inserir(no->esq, fila);
		if(no->dir != NULL)
			inserir(no->dir, fila);
	}
}

int main(){
	tipoNo* raiz = NULL;
	raiz = inserirNo(raiz, 5);
	raiz = inserirNo(raiz, 3);
	raiz = inserirNo(raiz, 8);
	raiz = inserirNo(raiz, 2);
	raiz = inserirNo(raiz, 4);
	raiz = inserirNo(raiz, 9);

	printf("PRE-ORDEM:\n");
	pre_ordem(raiz);
	printf("\nEM-ORDEM:\n");
	em_ordem(raiz);
	printf("\nPÓS-ORDEM:\n");
	pos_ordem(raiz);
	printf("\n");
	printf("PERCURSO EM LARGURA:\n");
	percurso_largura(raiz);
	printf("\n");
	if(buscaNo(raiz, 9) != NULL)
		printf("numero encontrado!\n");
}
