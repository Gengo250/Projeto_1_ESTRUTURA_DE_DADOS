#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"

int main(){
int op;
Animal pet;
Fila *Normal = CriaFila();
Fila *Emergencia = CriaFila();
Fila *Removidos = CriaFila();


do
{
  printf("----- ATENDIMENTOS DE PETS -----------------------------\n");
  printf("1 - Cadastrar um Pet\n2 - Atender um pet\n3 - Buscar um pet (nome ou ID)\n4 - Imprimir Relatorio com todos os pets\n5 - Imprimir proximos pets atendidos\n6 - Imprimir todos os pets ja atendidos\n7 - Sair\n");
  printf("--------------------------------------------------------\n");
  printf("Escolha sua opcao: ");
  scanf("%d", &op);
  
  limpaTela();

  switch (op)
  {
    
  case 1:
    
    InsereFila(Emergencia, Normal);
    //printf("\nFila Normal (após cadastro):\n");
    //imprimeFila(Normal); //teste para debugar
    op = 0;
  break;

  case 2:
  break;

  case 3:
  break;
  
  case 4:
  printf("Imprimindo a fila normal de espera: \n");
  imprimeFila(Normal);
  printf("Imprimindo a fila emergencial de espera:\n ");
  imprimeFila(Emergencia);
  op = 0;
  break;
  
  case 5:
  break;
  
  case 6:
  break;
  
  default:
    break;
  }

  

} while (op < 1 || op > 6);


  return 0;
}