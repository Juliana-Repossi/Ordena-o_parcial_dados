#ifndef INTEIROS_H
#define INTEIROS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct inteiro inteiro; 


/*
 retorna o campo quantidade da estrutura inteiros
*/
int RetornaQtd(inteiro *inteiros);

/*
 Retorna o valor daquela posicao do vetor
*/
int RetornaValorPosicao(inteiro *inteiros,int posicao);

/*
 Aloca um vetor de inteiros do tamanho da quantidae passada na primeira linha do arquivo e armazena essa quantidade de valores inteiros nesse vetor. Retorna o vetor alocado dinamicamente.
*/
static inteiro* CriaVetorInteiros(FILE *arq);

/*
  cria vetor de tam posições, cada uma delas com a mesma base de dados recebida do arquivo, usando a função auxiliar "CriaVetorInteiros" para que cada tipo de ordenação tenha seus dados individuais e inalterados
*/
inteiro** CriaVetoresInteiros(FILE *arq, int tam);

void ImprimeInteiros(inteiro *inteiros);

/*
  Compara dois inteiros da posicao passada e retorna:
  > 0 : se p1 > p2;
  = 0 : se p1 = p2;
  < 0 : se p1 < p2; 
*/
int Compara(int n1, int n2, inteiro *inteiros);

/*
  Troca os valores das duas posições
*/
void Troca(int n1, int n2, inteiro *inteiros);

/*
 A posicao p1 recebe o valor da posição p2 
*/
void Recebe(int p1, int p2, inteiro *inteiros);

/*
 A posicao p1 recebe o valor 
*/
void RecebeValor(int p1, int valor, inteiro *inteiros);

void LiberaInteiros (inteiro **inteiros, int tam);

#endif
