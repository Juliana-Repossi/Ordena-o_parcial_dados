#include "../include/inteiros.h"

struct inteiro
{
 int qtd;
 int *vetor; 
}; 

int RetornaQtd(inteiro *inteiros)
{
  return inteiros->qtd;
}

int RetornaValorPosicao(inteiro *inteiros,int posicao)
{
  return inteiros->vetor[posicao];
}

static inteiro* CriaVetorInteiros(FILE *arq)
{
  //aloca um tipo inteiro
  inteiro *inteiros = (inteiro*)calloc(1,sizeof(inteiro));

  //a primeira linha contem a quantidade de itens do arquivo
  fscanf(arq,"%d\n",&inteiros->qtd);  

  //lê o arquivo e armazena inteiros em um vetor alocado dinamicamente
  inteiros->vetor = (int*)malloc(inteiros->qtd*sizeof(int));

  for(int i=0; i<inteiros->qtd; i++)
  {
    fscanf(arq,"%d\n",&inteiros->vetor[i]);
  }

  //teste de funcionamento : ok!
  //ImprimeInteiros(inteiro *inteiros);

  return inteiros;
}

inteiro** CriaVetoresInteiros(FILE *arq, int tam)
{

  inteiro** vetores = (inteiro**)malloc(tam*sizeof(inteiro*));

  vetores[0] = CriaVetorInteiros(arq);

  for(int i=1; i< tam; i++)
  {
    vetores[i] = (inteiro*)malloc(sizeof(inteiro));

    //copia os dados
    vetores[i]->qtd = vetores[0]->qtd;
    vetores[i]->vetor = (int*)malloc(vetores[0]->qtd * sizeof(int));

    //faz a cópia do vetor a ser ordenado
    for(int j=0; j<vetores[0]->qtd; j++)
    {
      vetores[i]->vetor[j] = vetores[0]->vetor[j];
    }
    //teste ok!
    //ImprimeInteiros( vetores[i]);
  }
  return vetores;
}

void ImprimeInteiros(inteiro *inteiros)
{
    for(int i=0; i<inteiros->qtd; i++)
  {
    printf("%d - %d\n", i+1 , inteiros->vetor[i]);
  }
}

int Compara(int n1, int n2, inteiro *inteiros)
{
  return inteiros->vetor[n1] - inteiros->vetor[n2];
}

void Troca(int n1, int n2, inteiro *inteiros)
{
  int aux = inteiros->vetor[n1];
  inteiros->vetor[n1] = inteiros->vetor[n2];
  inteiros->vetor[n2] = aux;
}

void Recebe(int p1, int p2, inteiro *inteiros)
{
  inteiros->vetor[p1]=inteiros->vetor[p2];
}

void RecebeValor(int p1, int valor, inteiro *inteiros)
{
  inteiros->vetor[p1]=valor;
}

void LiberaInteiros (inteiro **inteiros, int tam)
{
  if(inteiros != NULL)
  {
    for(int i = 0; i<tam; i++)
    {
      if(inteiros[i] != NULL)
      {
      free(inteiros[i]->vetor);
      free(inteiros[i]);
      }
    }
  }
  free(inteiros);
}






