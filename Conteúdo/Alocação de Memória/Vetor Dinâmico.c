/*Como alocar um vetor dinâmico?*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int i, tam, *vet;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam); 
  srand(time(NULL)); 

  vet = malloc(tam * sizeof(int)); 

  if(vet){
    printf("Memoria alocada com sucesso!\n");
    for(i=0; i<tam; i++){
      *(vet + i) = rand() % 100; 
    }
    printf("\n"); 
    for(i=0; i<tam; i++){
      printf("%d ", *(vet+i));  
    }
  }else{
    printf("Erro ao alocar memoria!\n");
  }
  
  return 0;
}
