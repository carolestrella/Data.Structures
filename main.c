#include "pilha.h"
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

int main(){
	int op, flag = 1;
	system(CLEAR);
	while(flag){
		printf("\n\t ESCOLHA UMA OPCAO:\n\n");
		printf("1. RESOLUCAO DE EXPRESSAO\n2. CALCULADORA\n3. SAIR\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				resexpressao();
				break;
			case 2:
				modocalculadora();
				break;
			case 3:
				flag = 0;
				break;
			default: printf("Essa opcao nao eh valida!\n");
				break;
		}
	}
	return 0;
}