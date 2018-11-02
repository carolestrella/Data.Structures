/**
*@file calculadora.c
*@author Carolina Estrella Machado
*@date 19 october 2018
*@brief implementacao das funcoes contidas no arquivo calculadora.h
*/

#include "pilha.h"
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

/**
*@brief a funcao operando retorna 1 caso o caractere for um operando e 0 caso contrario
*@param x
*@return bool
*/

int operando(char x){
	if((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x >= 97 && x <= 121) || x == ' ' || x == '.' || x == ',')
		return 1;
	return 0;
}

/**
*@brief a funcao operando retorna 1 caso o caractere for um operador e 0 caso contrario
*@param x
*@return bool
*/

int operador(char x){
	if(x == '+' || x == '-' || x == '*' || x == '/')
		return 1;
	return 0;
}

/**
*@brief a funcao verifica a prioridade de um operador sob o outro
*@param x
*@return bool
*/

int prioridade(char x){
	if(x == '*' || x == '/')
		return 2;
	else if(x == '+' || x == '-')
		return 1;
	return 0;
}

/**
*@brief a funcao converte recebe uma expressao em char e a converte para double
*@param expressao
*@return result
*/

double converte (char* expressao){
	int i, j, q=0;
	double result=0;
	for(i=0; i < strlen(expressao); i++){
		if(expressao[i] == ',' || expressao[i] == '.'){
			q = i;
		}
	}
	if(q){ 
		for(i = (q-1), j=0; j < q; i--, j++){
			result += (expressao[j] - '0') * pow(10,i);
		}
		for(i=0, j = (q+1); j < strlen(expressao); i++, j++){
			result += (expressao[j] - '0') / pow(10,i+1);
		}
	} 
	else{
		for(i = (strlen(expressao)-1), j = 0; j < strlen(expressao); i--, j++){
			result += (expressao[j] - '0') * pow(10,i);
		}
	}
	return result;
}

/**
*@brief a funcao resolve recebe a notacao pos-fixa da expressao, resolvendo-a e retornando o valor encontrado
*@param posfixa
*@return result
*/

double resolve(char* posfixa){
	pilha* pilha = aloca_pilha();
	char aux[1000];
	int i, j, k=0;
	double total, aux1, aux2, resultado;

	for(i=0; i < strlen(posfixa); i++){
		if(operando(posfixa[i]) && posfixa[i] != ' '){
			for(j=i; posfixa[j] != ' '; j++){
				aux[k] = posfixa[j];
				k++;
			}
			aux[k] = '\0';
			i=j;
			k=0;
			pushdouble(converte(aux),pilha);
		}
		else if(operador(posfixa[i])){
			aux1 = topdouble(pilha);
			popdouble(pilha);
			aux2 = topdouble(pilha);
			popdouble(pilha);
			switch(posfixa[i]){
				case '*':
					total = aux1 * aux2;
					break;
				case '/':
					total = aux2 / aux1;
					break;
				case '+':
					total = aux1 + aux2;
					break;
				case '-':
					total = aux2 - aux1;
					break;
			}
			pushdouble(total, pilha);
		}
	}
	resultado = topdouble(pilha);
	popdouble(pilha);
	libera_pilhadouble(pilha);
	return resultado;
}

/**
*@brief a funcao transformaposfixa recebe uma expressao em char na forma infixa transformando e armazenando a nova expressao na variavel posfixa
*@param1 expressao @param2 posfixa
*@return void
*/

void transformaposfixa(char* expressao, char* posfixa){
	No* pilha = aloca_no();
	int i, j=0;

	for(i=0; i < strlen(expressao); i++){
		if(operando(expressao[i])){
			posfixa[j] = expressao[i];
			j++;
		}
		else if(operador(expressao[i])){
			while(!esta_vazia(pilha) && ((prioridade(top(pilha))) >= (prioridade(expressao[i])))){
				posfixa[j] = top(pilha);
				pop(pilha);
				j++;
			}
			push(expressao[i], pilha);
		}
		else if(expressao[i] == '('){
			push(expressao[i], pilha);
		}
		else if(expressao[i] == ')'){
			while(top(pilha) != '('){
				posfixa[j] = top(pilha);
				pop(pilha);
				j++;
			}
			if(top(pilha) == '('){
				pop(pilha);
			}
		}
	}
	while(!esta_vazia(pilha)){
		posfixa[j] = top(pilha);
		pop(pilha);
		j++;
	}
	posfixa[j] = '\0';
	libera_pilha(pilha);	
}

/**
*@brief a funcao verifica se os inicializadores e finalizadores de escopo estao sendo utilizados da forma correta na expressao
*@param expressao
*@return bool
*/

int verifica(char* expressao){
	No* pilha = aloca_no();
	int i, flag=1;
	for(i=0; i < strlen(expressao); i++){
		switch(expressao[i]){
			case '(':
				push(expressao[i], pilha);
				break;
			case '[':
				push(expressao[i], pilha);
				break;
			case '{':
				push(expressao[i], pilha);
				break;
			case ')':
				if(esta_vazia(pilha)){
					printf("A equacao nao eh valida!\n");
					libera_pilha(pilha);
				}
				else{
					if(top(pilha) != '('){
						flag = 0;
					}
					pop(pilha);
				}
				break;
			case ']':
				if(esta_vazia(pilha)){
					printf("A equacao nao eh valida!\n");
					libera_pilha(pilha);
				}
				else{
					if(top(pilha) != '['){
						flag = 0;
					}
					pop(pilha);
				}
				break;
			case '}':
				if(esta_vazia(pilha)){
					printf("A equacao nao eh valida!\n");
					libera_pilha(pilha);
				}
				else{
					if(top(pilha) != '{'){
						flag = 0;
					}
					pop(pilha);
				}
				break;
		}
	}
	if(!esta_vazia(pilha) || flag == 0){
		printf("A equacao nao eh valida!\n");
		libera_pilha(pilha);
		return 0;
	}
	else{
		printf("Equacao valida!\n");
		libera_pilha(pilha);
		return 1;
	}
}

/**
*@brief a funcao semespaco recebe uma expressao em char e verifica se o usuario a digitou com espaco
*@param expressao
*@return bool
*/

int semespaco(char* expressao){
	int i;
	for(i=0; i < strlen(expressao); i++){
		if(expressao[i] == ' ')
			return 0;
	}
	return 1;
}

/**
*@brief a funcao inicializador verifica inicializadores de escopo
*@param op
*@return bool
*/

int inicializador(char op){
	if(op == '(' || op == '[' || op == '{')
		return 1;
	return 0;
}

/**
*@brief a funcao inicializador verifica finalizadores de escopo
*@param op
*@return bool
*/

int finalizador(char op){
	if(op == ')' || op == ']' || op == '}')
		return 1;
	return 0;
}

/**
*@brief a funcao definetipo recebe um caractere e define seu tipo (inicializador, finalizador, operando ou operador)
*@param op
*@return bool
*/

int definetipo(char op){
	if(inicializador(op) || finalizador(op))
		return -1;
	else if(operando(op))
		return 0;
	else
		return 1;
}

/**
*@brief a funcao colocaespaco recebe uma expressao em char sem espaco e coloca espaco entre os operandos e operadores
*@param1 expressao @param2 aux
*@return void
*/

void colocaespaco(char* expressao, char* aux){
	int i, j=0;
	char ant;
	for(i=0; i < strlen(expressao); i++){
		if(definetipo(expressao[i]) != definetipo(ant)){
			aux[j] = ' ';
			aux[j+1] = expressao[i];
			j+=2;
		}
		else{
			aux[j] = expressao[i];
			j++;
		}
		ant = expressao[i];	
	}
	aux[j] = '\0';	
}

/**
*@brief a funcao quantidade retorna a quantidade de elementos na pilha
*@param Pilha
*@return qtd
*/

int quantidade(pilha* Pilha){
	int qtd=0;
	elemento* e = Pilha->topo;
	while(e != NULL){
		qtd++;
		e = e->prox;
	}
	return qtd;
}

/**
*@brief a funcao modorepeticao recebe o operador escolhido e um ponteiro tipo pilha para fazer as operacoes desejadas e empilha o resultado novamente na pilha
*@param1 op @param2 Pilha
*@return void
*/

void modorepeticao(char op, pilha* Pilha){
	double aux1, aux2, result;
	switch(op){
		case '+':
			result = 0;
			while(Pilha->topo->prox != NULL){
				aux1 = topdouble(Pilha);
				popdouble(Pilha);
				aux2 = topdouble(Pilha);
				popdouble(Pilha);
				result = aux1 + aux2;
				pushdouble(result, Pilha);
			}

			break;
		case '-':
			while(Pilha->topo->prox != NULL){
				aux1 = topdouble(Pilha);
				popdouble(Pilha);
				aux2 = topdouble(Pilha);
				popdouble(Pilha);
				result = aux1 - aux2;
				pushdouble(result, Pilha);
			}
			break;
		case '*':
			while(Pilha->topo->prox != NULL){
				aux1 = topdouble(Pilha);
				popdouble(Pilha);
				aux2 = topdouble(Pilha);
				popdouble(Pilha);
				result = aux1 * aux2;
				pushdouble(result, Pilha);
			}
			break;
	}
}

/**
*@brief a funcao modonormal recebe o operador escolhido e um ponteiro tipo pilha para fazer as operacoes desejadas e empilha o resultado novamente na pilha
*@param1 op @param2 Pilha
*@return void
*/

void modonormal(char op, pilha* Pilha){
	double aux1, aux2, result;
	switch(op){
		case '+':
			aux1 = topdouble(Pilha);
			popdouble(Pilha);
			aux2 = topdouble(Pilha);
			popdouble(Pilha);
			result = aux1 + aux2;
			pushdouble(result, Pilha);
			break;
		case '-':
			aux1 = topdouble(Pilha);
			popdouble(Pilha);
			aux2 = topdouble(Pilha);
			popdouble(Pilha);
			result = aux1 - aux2;
			pushdouble(result, Pilha);
			break;
		case '*':
			aux1 = topdouble(Pilha);
			popdouble(Pilha);
			aux2 = topdouble(Pilha);
			popdouble(Pilha);
			result = aux1 * aux2;
			pushdouble(result, Pilha);
			break;
		case '/':
			aux1 = topdouble(Pilha);
			popdouble(Pilha);
			aux2 = topdouble(Pilha);
			popdouble(Pilha);
			result = aux1 / aux2;
			pushdouble(result, Pilha);
			break;
	}
}

/**
*@brief a funcao modocalculadora pede ao usuario que digite os operadores e operandos que deseja para que sejam colocados na pilha e a operacao seja realizada
*@param void
*@return void
*/

void modocalculadora(){
	system(CLEAR);
	pilha* pilha = aloca_pilha();
	int i, j=0, flag=0;
	double x, copias, numero;
	char op[1000], aux[1000];
	printf("\t MODO CALCULADORA\n\n");
	printf("Digite um operador ou operando valido de acordo com as instrucoes no README.txt:\n");
	printf("Para sair, digite 'quit'.\n");
	printdouble(pilha);
	printf("->");
	scanf(" %s", op);
	while(strcmp(op, "quit") !=0){
		if(op[0] == '-' && op[1] != '!' && op[1] != '\0'){ /*se for um numero negativo*/
			for(i=1; i < strlen(op); i++){
				aux[j] = op[i];
				j++;
			}
			aux[j] = '\0';
			j=0;
			x = -converte(aux);
			pushdouble(x,pilha);
		}
		else if(op[0] >= '0' && op[0] <= '9'){
			pushdouble(converte(op),pilha);
		}
		else if(operador(op[0])){
			if(quantidade(pilha) < 2){
				flag=1;
			}
			else{
				if(op[1] == '!'){
					modorepeticao(op[0], pilha);
				}
				else{
					modonormal(op[0], pilha);
				}
			}
		}
		else if(op[0] == 'c'){
			if(quantidade(pilha) < 2){
				flag=1;
			}
			else{
				copias = topdouble(pilha);
				popdouble(pilha);
				numero = topdouble(pilha);
				popdouble(pilha);
				while(copias--){
					pushdouble(numero, pilha);
				}
			}	
		}
		if(flag){
			system(CLEAR);
			printf("\t MODO CALCULADORA\n\n");
			printf("Digite um operador ou operando valido:\n");
			printf("Para sair, digite 'quit'.\n\n");
			printdouble(pilha);
			printf("*** Numero de operandos insuficiente! ***\n");
		}
		else{
			system(CLEAR);
			printf("\t MODO CALCULADORA\n\n");
			printf("Digite um operador ou operando valido:\n");
			printf("Para sair, digite 'quit'.\n\n");
			printdouble(pilha);
		}
		flag=0;
		printf("->");
		scanf(" %s", op);
	}
	libera_pilhadouble(pilha);
}

/**
*@brief a funcao resexpressao pede ao usuario que digite uma expressao que sera verificado, transformada para a forma posfixa e resolvida
*@param void
*@return void
*/

void resexpressao(){
	system(CLEAR);
	char expressao[1000], posfixa[1000], nova[1000];
	printf("\t MODO RESOLUCAO DE EXPRESSAO\n\n");
	printf("Digite uma expressao valida - ex: (2*3)+5 ou ( 2 * 3 ) + 5\n");
	scanf(" %[^\n]s ", expressao);
	if(semespaco(expressao)){
		colocaespaco(expressao,nova);
		strcat(nova, " ");
		if(verifica(expressao)){
			printf("forma infixa = %s\n", expressao);
			transformaposfixa(nova,posfixa);
			printf("forma posfixa = %s\n", posfixa);
			printf("Resultado = %lf\n", resolve(posfixa));
		}
	}
	else{
		strcat(expressao, " ");
		if(verifica(expressao)){
			printf("forma infixa = %s\n", expressao);
			transformaposfixa(expressao,posfixa);
			printf("forma posfixa = %s\n", posfixa);
			printf("Resultado = %lf\n\n", resolve(posfixa));
		}
	}
}
