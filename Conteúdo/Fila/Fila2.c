/*Fila 2 -> FIFO(First Int, Firts Out)*/
#include<stdlib.h>
#include <stdio.h>

typedef struct no{
  int valor;
  struct no*proximo;
}No;

//Função para inserir um elemento na fila
void inserir_na_fila(No **fila, int num){
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*fila == NULL){
      *fila = novo;
    }else{
      aux = *fila;
      while(aux->proximo){
        aux = aux->proximo;
      }
      aux->proximo = novo; 
    }
  }else{
    printf("\nErro ao alocar memoria!\n");
  }
}

//Função para remover um elemento da fila
No* remover_da_fila(No **fila){
  No *remover = NULL;
  if(*fila){
    remover = *fila;
    *fila = remover->proximo;
  }else{
    printf("\n\tFila Vazia!\n");
  }
  return remover;
}

void imprimir(No *fila){
  printf("\t-------FILA-------\n\t");
  while(fila){
    printf("%d ", fila->valor);
    fila = fila->proximo;
  }
  printf("\n\t-------FIM FILA-------\n");
}


int main(){
  No *r, *fila = NULL; 
  int opcao,valor;

  do{
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("\nDigite um numero: ");
        scanf("%d", &valor);
        inserir_na_fila(&fila, valor);
        break;
      case 2:
        r = remover_da_fila(&fila);
        if(r){
          printf("Removido: %d\n", r->valor); 
          free(r);
        }else{
          printf("Erro ao remover!\n");
        }
        break;
      case 3:
        imprimir(fila); 
        break;
      default: 
        if(opcao != 0){
          printf("\nOpcao invalida!\n");
        }
    }
  }while(opcao != 0);
  return 0;
}
