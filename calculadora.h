/**
*@file calculadora.h
*@author Carolina Estrella Machado
*@date 19 october 2018
*@brief assinaturas das funcoes que serao implementadas no arquivo calculadora.c
*/

#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

/**
*@brief a funcao operando retorna 1 caso o caractere for um operando e 0 caso contrario
*@param x
*@return bool
*/

int operando(char x);

/**
*@brief a funcao operando retorna 1 caso o caractere for um operador e 0 caso contrario
*@param x
*@return bool
*/

int operador(char x);

/**
*@brief a funcao verifica a prioridade de um operador sob o outro
*@param x
*@return bool
*/

int prioridade(char x);

/**
*@brief a funcao converte recebe uma expressao em char e a converte para double
*@param expressao
*@return result
*/

double converte (char* expressao);

/**
*@brief a funcao resolve recebe a notacao pos-fixa da expressao, resolvendo-a e retornando o valor encontrado
*@param posfixa
*@return result
*/

double resolve(char* posfixa);

/**
*@brief a funcao transformaposfixa recebe uma expressao em char na forma infixa transformando e armazenando a nova expressao na variavel posfixa
*@param1 expressao @param2 posfixa
*@return void
*/

void transformaposfixa(char* expressao, char* posfixa);

/**
*@brief a funcao verifica se os inicializadores e finalizadores de escopo estao sendo utilizados da forma correta na expressao
*@param expressao
*@return bool
*/

int verifica(char* expressao);

/**
*@brief a funcao semespaco recebe uma expressao em char e verifica se o usuario a digitou com espaco
*@param expressao
*@return bool
*/

int semespaco(char* expressao);

/**
*@brief a funcao inicializador verifica inicializadores de escopo
*@param op
*@return bool
*/

int inicializador(char op);

/**
*@brief a funcao inicializador verifica finalizadores de escopo
*@param op
*@return bool
*/

int finalizador(char op);

/**
*@brief a funcao definetipo recebe um caractere e define seu tipo (inicializador, finalizador, operando ou operador)
*@param op
*@return bool
*/

int definetipo(char op);

/**
*@brief a funcao colocaespaco recebe uma expressao em char sem espaco e coloca espaco entre os operandos e operadores
*@param1 expressao @param2 aux
*@return void
*/

void colocaespaco(char* expressao, char* aux);

/**
*@brief a funcao quantidade retorna a quantidade de elementos na pilha
*@param Pilha
*@return qtd
*/

int quantidade(pilha* Pilha);

/**
*@brief a funcao modorepeticao recebe o operador escolhido e um ponteiro tipo pilha para fazer as operacoes desejadas e empilha o resultado novamente na pilha
*@param1 op @param2 Pilha
*@return void
*/

void modorepeticao(char op, pilha* Pilha);

/**
*@brief a funcao modonormal recebe o operador escolhido e um ponteiro tipo pilha para fazer as operacoes desejadas e empilha o resultado novamente na pilha
*@param1 op @param2 Pilha
*@return void
*/

void modonormal(char op, pilha* Pilha);

/**
*@brief a funcao modocalculadora pede ao usuario que digite os operadores e operandos que deseja para que sejam colocados na pilha e a operacao seja realizada
*@param void
*@return void
*/

void modocalculadora();

/**
*@brief a funcao resexpressao pede ao usuario que digite uma expressao que sera verificado, transformada para a forma posfixa e resolvida
*@param void
*@return void
*/

void resexpressao();

#endif