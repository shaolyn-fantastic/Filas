#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TAMANHO 5

//-----------estrutura de fila estatica---------------------------
//tamanho fixo definido{tamanho}
//Q = vetor[tamanho]
//inicio (int), variavel indexadora
//fim(int), variavel indexadora
//contador - qtde elementos dentro do vetor

typedef struct{
  int inicio;//controla o inicio da fila
  int fim; //controla o fim da fila
  int array[TAMANHO];//vetor de 5 posições
  int qtdeElementos;
} FilaEstatica;

//inicialização
void IniciaPilhaEstatica(FilaEstatica* fila){
  fila->qtdeElementos = 0;
  fila->inicio = 0;
  fila->fim = -1;
}

//estrutura esta vazia
bool estaVazia(FilaEstatica* fila){

return(fila->qtdeElementos == 0);
}

//estrutura esta cheia
bool estaCheia(FilaEstatica* fila){

  return(fila->qtdeElementos == TAMANHO);
}

int IncrementaIndice(int i){
  int novoValor = (i+1)%TAMANHO;
  return novoValor;
}
//inserções são feitas no final da fila
void EnfileirarEstatica(FilaEstatica* fila, int x){
//só pode ser inserido se a fila não estiver cheia
if(!estaCheia(fila)){
  //incrementa o fim
  fila->fim= IncrementaIndice(fila->fim);
//TODO: fim = incrementaIndex(fim)// buffer circular

  //atribui o valor de x na poisção indicada pelo fim no array
  fila->array[fila->fim] = x;
  //incrementa a quantidade de elementos
  fila->qtdeElementos++;
}else{
  printf("nao pode ser inserido, pilha cheia\n");
  }
}//EnfileirarEstatica

//tamanho da estrutura
int TamanhoFilaEstatica(FilaEstatica* fila){
  return(fila->qtdeElementos);
}

//Imprimir fila estatica
void ImprimiFilaEstatica(FilaEstatica* fila){
  printf("fila = {");
  //TODO: fim = incrementaIndex(fim)// buffer circular
  int n = TamanhoFilaEstatica(fila);
  for(int i = 0; i < n; i++){
    int indice = (fila->inicio + i) % TAMANHO;
    printf("%d ",fila->array[indice]);
  }
  printf("}\n");
}

//remoções são feitas no inicio da fila
int DesenfileirarFilaEstatica(FilaEstatica* fila){
  int ret;
//só posso remover elementos se a fila não estiver vazia
if(!estaVazia(fila)){
  //salvar o dado que precisa ser retornado
  ret = fila->array[fila->inicio];
  //incrementar a posição do inicio
  fila->inicio = IncrementaIndice(fila->inicio);
  //decrementa a quantidade de elementos
   fila->qtdeElementos--;
  //retornar o valor
  return ret;
}else{
  printf("fila vazia, impossivel retirar");
}
}//DesenfileirarFilaEstatica

//consultar o primeiro elemento
int ConsultaInicioFilaEstatica(FilaEstatica *fila){
  int inicio;
  return inicio = fila->array[fila->inicio];
  return inicio;
}

//consultar o ultimo elemento
int ConsultaFimFilaEstatica(FilaEstatica *fila){
  int fim;
  return fim = fila->array[fila->fim];
  return fim;
}

//duas extremidades manipulaveis
//inicio de fila(primeiro elemento)
//fim da fila (ultimo elemento)




int main(int argc, char const *argv[]) {
  FilaEstatica f;
  IniciaPilhaEstatica(&f);
  if(estaVazia(&f)){
    printf("esta vazia\n");
  }
  if(!estaCheia(&f)){
    printf("nao esta cheia\n");
  }
  EnfileirarEstatica(&f,42);
  // ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,43);
  // ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,44);
  // ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,45);
  // ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,46);
  ImprimiFilaEstatica(&f);

  int removido;
  removido = DesenfileirarFilaEstatica(&f);
  ImprimiFilaEstatica(&f);
  removido = DesenfileirarFilaEstatica(&f);
  ImprimiFilaEstatica(&f);
  removido = DesenfileirarFilaEstatica(&f);
  ImprimiFilaEstatica(&f);


  EnfileirarEstatica(&f,1);
   ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,2);
   ImprimiFilaEstatica(&f);
  EnfileirarEstatica(&f,3);
   ImprimiFilaEstatica(&f);

printf("inicio da pilha = %d\n",ConsultaInicioFilaEstatica(&f));
printf("fim da pilha = %d\n",ConsultaFimFilaEstatica(&f));
  return 0;
}
