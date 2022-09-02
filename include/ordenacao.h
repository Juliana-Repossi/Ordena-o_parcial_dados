#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "inteiros.h"
#include <string.h>
#include <time.h>

/*
  struct para armazenar dados para os relatorios
*/
typedef struct dadosOrdenacao dadosOrdenacao;

/*
  Aloca o vetor de ponteiros para armazenar os resultados de cada um dos algoritmos
*/
dadosOrdenacao** alocaFichaResultados(int tam);

/*
  Aloca uma estrutura de dadoOrdenação na posicao passada no vetor de ponteiros 
*/
void alocaUmResultado(int posicao, dadosOrdenacao **dados);

void selectionSort(inteiro *inteiros, int top, dadosOrdenacao* resul);

void insertionSort(inteiro *inteiros, int top, dadosOrdenacao* resul);

void quickSort(inteiro *inteiros, int esquerda, int direita, int top, dadosOrdenacao* resul);

void shellSort(inteiro *inteiros, int top, dadosOrdenacao *resul);

void heapSort(inteiro *inteiros, int top, dadosOrdenacao *resul);

void Relatorio1(int top, dadosOrdenacao **dados,inteiro **inteiros);

void Relatorio2(dadosOrdenacao **dados);

void Relatorio3(dadosOrdenacao **dados, char *arquivo, int top, inteiro **inteiros);

void liberaDadosOrdenacao(dadosOrdenacao **dados, int tam);

#endif