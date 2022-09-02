#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/ordenacao.h"

int main(int argc, char **argv) {

  //verificar se recebeu 4 argumentos
  if(argc != 4)
  {
    printf("Você não seguiu as regras de compilação do programa e passou ");
    if(argc < 4) { printf("menos"); }
    else { printf("mais"); }
    printf(" de 4 comandos\n"); 
    exit(1);
  }

  int top = atoi(argv[2]);

  FILE *arq = fopen(argv[3],"r");

   if(arq == NULL)
    {
      printf("Erro na abertura do arquivo %s\n",argv[3]);
      exit(2);
    }

  //por conta das multiplas ordenações, vetor de 5 posicoes para cada
  inteiro **vetores = CriaVetoresInteiros(arq, 5);

  //fechar o arquivo
  fclose(arq);

  int op;
  
  //vetor para armazenar resultados
  // 0(s), 1(i), 2(e), 3(q), 4(h)
  dadosOrdenacao **resultados = alocaFichaResultados(5);

  //receber opções por linha de comando
  while( (op = getopt (argc , argv,"asieqh123")) != -1 )
  {
    switch(op)
    {
      case 'a':
       alocaUmResultado(0,resultados);
       selectionSort(vetores[0],top,resultados[0]);

       alocaUmResultado(1,resultados);
       insertionSort(vetores[1],top,resultados[1]);

       alocaUmResultado(2,resultados);
       shellSort(vetores[2],top, resultados[2]);

       alocaUmResultado(3,resultados);
       quickSort(vetores[3], 0, RetornaQtd(vetores[3])-1,top,resultados[3]);

       alocaUmResultado(4,resultados);
       heapSort(vetores[4],top,resultados[4]);
       break;

      case 's':
       alocaUmResultado(0,resultados);
       selectionSort(vetores[0],top,resultados[0]);
       break;
      
      case 'i':
       alocaUmResultado(1,resultados);
       insertionSort(vetores[1],top,resultados[1]);
       break;

      case 'e':
       alocaUmResultado(2,resultados);
       shellSort(vetores[2],top, resultados[2]);
       break;

      case 'q':
       alocaUmResultado(3,resultados);
       quickSort(vetores[3], 0, RetornaQtd(vetores[3])-1,top,resultados[3]);
       break;

      case 'h':
       alocaUmResultado(4,resultados);
       heapSort(vetores[4],top,resultados[4]);
       break;

      case '1':
       Relatorio1(top,resultados,vetores);
       break;
      
      case '2':
       Relatorio2(resultados);
       break;
      
      case '3':
       Relatorio3(resultados,argv[3],top, vetores);
       break;        
    }   
  }

  liberaDadosOrdenacao(resultados,5);
  LiberaInteiros (vetores,5);

  return 0;
}