#include "../include/ordenacao.h"

struct dadosOrdenacao
{
  double tempoCPU;
  int comparacoes;
  int trocas;
  char algoritmo[10];
};


dadosOrdenacao** alocaFichaResultados(int tam)
{
  dadosOrdenacao **resul = (dadosOrdenacao**)calloc(tam,sizeof(dadosOrdenacao*));

  return resul;
}

void alocaUmResultado(int posicao, dadosOrdenacao **dados)
{
  dados[posicao] = (dadosOrdenacao*)calloc(1,sizeof(dadosOrdenacao));
}

void selectionSort(inteiro *inteiros, int top, dadosOrdenacao *resul)
{
  //tipo de ordenação
  strcpy(resul->algoritmo, "Selection");

  int maior, troca;

  struct timespec beginCPU, endCPU; 
  double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  //como é ordenação parcial, só vai executar para os top primeiros
  for (int i = 0; i < top; i++)
  {
    //posição do maior
    maior = i;

    //verifica se é o maior da lista
    for (int j = i + 1; j < RetornaQtd(inteiros); j++)
    {
      //faz comparação
      resul->comparacoes++;

     if(Compara(maior,j,inteiros) < 0)
     {
       maior = j;
       troca = 1;
     }
    }
    if (troca == 1)
    {
      //faz troca 
      resul->trocas++;
      Troca(i, maior, inteiros);
      troca = 0;
    }
  }

  // Termina de medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  // calcula o tempo de CPU
  seconds = endCPU.tv_sec - beginCPU.tv_sec;
  nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;        
  
  resul->tempoCPU = elapsed;
}

void insertionSort(inteiro *inteiros, int top,dadosOrdenacao *resul)
{
  //tipo de ordenação
  strcpy(resul->algoritmo, "Insertion");

  struct timespec beginCPU, endCPU; 
  double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  int i, j;

  for (i = 1; i < RetornaQtd(inteiros); i++) 
  {
    if(i >= top)
    {
      //já ordenou os top
      //só vai posicionar se for maior que o vetor[top-1]
      resul->comparacoes++;

      if(Compara(i,top-1,inteiros)>0)
      {
        resul->trocas++;
        Troca(top-1,i,inteiros);
        j = top - 2;
      }
      else
      {
        //não fazer ordenação 
        continue;
      }       
    }
    else
    {
      j = i - 1;
    }      
      
    while (j >= 0)
    {
      resul->comparacoes ++;

      if (Compara(j+1,j,inteiros)>0)
      {
        resul->trocas++;
        Troca(j+1,j,inteiros);
      }      
      j = j - 1;     
    }
  }

  // Termina de medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  // calcula o tempo de CPU
  seconds = endCPU.tv_sec - beginCPU.tv_sec;
  nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;        
  
  resul->tempoCPU = elapsed;
}

void quickSort(inteiro *inteiros, int esquerda, int direita, int top, dadosOrdenacao *resul)
{
  //tipo de ordenação
  strcpy(resul->algoritmo, "Quick");

  struct timespec beginCPU, endCPU; 
  double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  int i, j, x, y;
  i = esquerda;
  j = direita;
  x = RetornaValorPosicao(inteiros,(esquerda + direita) / 2);

  while (i <= j)
  {
    resul->comparacoes++;
    while (RetornaValorPosicao(inteiros,i) > x && i < direita)
    {
      i++;
    }
    resul->comparacoes++;
    while (RetornaValorPosicao(inteiros,j) < x && j > esquerda)
    {
      j--;
    }
    if (i <= j)
    {
      if(i!=j)
      {
        resul->trocas++;
        Troca(i,j,inteiros);
      }    
      i++;
      j--;
    }
  }
  if (j > esquerda)
  {
    quickSort(inteiros, esquerda, j, top,resul);     
  }
  if (i < direita)
  {
    if( i <= top )
    {
     quickSort(inteiros, i, direita, top,resul);
    }
  }
  
  // Termina de medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  // calcula o tempo de CPU
  seconds = endCPU.tv_sec - beginCPU.tv_sec;
  nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;        
  
  resul->tempoCPU = elapsed;
}

void shellSort(inteiro *inteiros, int top, dadosOrdenacao *resul)
{
  //tipo de ordenação
  strcpy(resul->algoritmo, "Shell");

  struct timespec beginCPU, endCPU; 
  double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  int i , j , value;
  //primeira execução faz para todos
  int tam = RetornaQtd(inteiros);
  int gap = 1;

while(gap < tam)
  {
    gap = 3*gap+1;
  }

  while ( gap > 1) 
  {
    gap /= 3;
    for(i = gap; i < tam; i++) 
    {
      value = RetornaValorPosicao(inteiros,i);
      j = i - gap;
      
      while (j >= 0) 
      {
        resul->comparacoes++;
        if(value > RetornaValorPosicao(inteiros,j))
        {
          resul->trocas++;
          Recebe(j + gap, j, inteiros);
          j -= gap;
        }
        else
        {
          break;
        }
        
      }
      RecebeValor(j + gap, value, inteiros);
    }
    
    //depois da primeira execução é so observar as top primeiras posições do subvetores que surgem pela comparação do shell
    tam = gap*top;

    if(tam > RetornaQtd(inteiros))
    {
      tam = RetornaQtd(inteiros);
    }
  }
  // Termina de medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  // calcula o tempo de CPU
  seconds = endCPU.tv_sec - beginCPU.tv_sec;
  nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;        
  
  resul->tempoCPU = elapsed;
}

void heapSort(inteiro *inteiros, int top, dadosOrdenacao *resul)
{
  //tipo de ordenação
  strcpy(resul->algoritmo, "Heap");

  struct timespec beginCPU, endCPU; 
  double seconds, nanoseconds, elapsed;

  // Começa a medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beginCPU);

  int tam = RetornaQtd(inteiros);
  int i = RetornaQtd(inteiros)/2;
  int pai, filho, t;

  while(1)
  {
    if (i > 0) 
    {
      i--;
      t = RetornaValorPosicao(inteiros, i);
    } 
    else
    {
      tam--;
      t = RetornaValorPosicao(inteiros,tam);
      resul->trocas++;
      Recebe(tam,0, inteiros);
      // se já tiver ordenado os tops, finalizar
      if (RetornaQtd(inteiros) - tam == top)
      {
        break;
      } 
    }
    
    pai = i;
    filho = i * 2 + 1;

    while (filho < tam) 
    {
      resul->comparacoes++;
      if (filho + 1 < tam)
      {
        resul->comparacoes++;
        if(Compara(filho+1,filho,inteiros)>0)
        {
          filho++;
        }
      }
      resul->comparacoes++;
      if (RetornaValorPosicao(inteiros, filho) > t) 
      {
        resul->trocas++;
        Recebe(pai,filho,inteiros);
        pai = filho;
        filho = pai * 2 + 1;    
      }
      else
      {
        break;
      }
    }
   RecebeValor(pai,t,inteiros);
  }

  // Termina de medir o tempo
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU);

  // calcula o tempo de CPU
  seconds = endCPU.tv_sec - beginCPU.tv_sec;
  nanoseconds = endCPU.tv_nsec - beginCPU.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;        
  
  resul->tempoCPU = elapsed;
}


void Relatorio1(int top, dadosOrdenacao **dados,inteiro **inteiros)
{
  for(int j = 0; j < 5; j++)
  {
    if(dados[j]!= NULL)
    {
      printf("\n------------------%s------------------\n",dados[j]->algoritmo);    
      printf("Top %d para entrada\n",top);

      if(strcmp(dados[j]->algoritmo,"Heap")==0)
      {
        int max = RetornaQtd(inteiros[j]) - 1;

        for(int i = 0; i < top; i++)
        {
          printf("%d\n",RetornaValorPosicao(inteiros[j], max - i));
        }
      }
      else
      {
        for(int i = 0; i < top; i++)
        {
          printf("%d\n",RetornaValorPosicao(inteiros[j], i));
        }
      }
      printf("---------------------------------------------\n");
    }
  }
}

void Relatorio2(dadosOrdenacao **dados)
{
  for(int j = 0; j < 5; j++)
  {
    if(dados[j]!= NULL)
    {
      printf("\n------------------%s------------------\n",dados[j]->algoritmo);

      printf("Tempo de CPU: 	%.3f segundos\n",dados[j]->tempoCPU);
      printf("Comparações:    %d\n",dados[j]->comparacoes);
      printf("Trocas:	    	%d\n",dados[j]->trocas);

      printf("---------------------------------------------\n");
    }
  }
}

void Relatorio3(dadosOrdenacao **dados, char *arquivo, int top, inteiro **inteiros)
{
  for(int j = 0; j < 5; j++)
  {
    if(dados[j]!= NULL)
    {
      printf("\n-------------------------%s-------------------------\n",dados[j]->algoritmo);

      printf("[algoritmo	arquivo	tam.	T(top)	comp. 	trocas	tempo(s)]\n");
      printf("%s  %s  %d  %d  %d  %d  %.3f\n",dados[j]->algoritmo,arquivo,RetornaQtd(inteiros[j]),top, dados[j]->comparacoes, dados[j]->trocas,dados[j]->tempoCPU);
      
      printf("--------------------------------------------------\n");
    }
  }
}

void liberaDadosOrdenacao(dadosOrdenacao **dados, int tam)
{
  for(int i=0; i<tam; i++)
  {
    if(dados[i] != NULL)
    {
      free(dados[i]);
    }
  }
  free(dados);
}
