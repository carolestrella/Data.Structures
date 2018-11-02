/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   *  Universidade de Brasilia                                 *
   *                                                           *
   *  Instito de Ciencias Exatas                               *
   *  Departamento de Ciencia da Computacao                    *
   *                                                           *
   *  Estrutura de Dados - 2/2018                              *
   *                                                           *
   *  Aluna: Carolina Estrella Machado                         *
   *  Matricula: 180074792                                     *
   *  Turma: A                                                 *
   *                                                           *
   *  Versao do compilador: gcc (SUSE Linux) 4.8.5             *
   *  Compilado no terminal / Editado no Sublime               *                                                             
   *                                                           *
   *  Descricao: implementacao de uma calculadora que recebe   *
   *  as expressoes na forma infixa e transforma para a forma  *
   *  posfixa, resolvendo-a. Alem disso, tem a opcao modo      *
   *  calculadora, que recebe os numeros e realiza operacoes   *
   *  escolhidas.                                              *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

BIBLIOTECAS UTILIZADAS:

<stdlib.h>
<stdio.h>
<math.h>
<string.h>
"pilha.h"
"calculadora.h"

INSTRUCOES DE COMPILACAO:

Compilar no terminal com:
gcc -c calculadora.c
gcc -c pilha.c
gcc -o main main.c pilha.o calculadora.o -lm

Executar o comando: ./main