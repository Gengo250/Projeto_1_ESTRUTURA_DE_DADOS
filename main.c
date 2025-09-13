#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "biblioteca.h"

int main(){
setlocale(LC_ALL, "Portuguese");
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

  //limpaTela();

  switch (op)
  {

  case 1:

    InsereFila(Emergencia, Normal);
    //printf("\nFila Normal (após cadastro):\n");
    //imprimeFila(Normal); //teste para debugar
  break;

  case 2:
      Teste(Emergencia,Normal,Removidos);
  break;

  case 3:
      int id;
      char nome[50];
      int f;
      printf("Você quer procurar pelo ID (1) ou Nome (2)");
      scanf("%d", &f);
      if(f == 1){
      printf("\nDigite o ID que deseja procurar: ");
      scanf("%d", &id);
      procuraID(Emergencia,Normal,Removidos,id);
      }
      if(f == 2 ){
        printf("\nDigite o Nome que deseja procurar: ");
        scanf(" %49[^\n]", nome);
        procuraNome(Emergencia,Normal,Removidos,nome);
      }
      
  break;

  case 4:
        printf("\nNormal: ");
        imprimeFila(Normal);
        printf("--------------------------------------");

        printf("\nEmergencia: ");
        imprimeFila(Emergencia);
        printf("--------------------------------------");

        printf("\nAtendidos: ");
        imprimeFila(Removidos);

  break;

  case 5:
    printf("Imprimindo a fila normal de espera: \n");
    imprimeFila(Normal);
    printf("Imprimindo a fila emergencial de espera:\n ");
    imprimeFila(Emergencia);
  break;

  case 6:
    printf("Imprimindo o histórico de atendimentos:\n ");
    imprimeFila(Removidos);
  break;
  case 7:
    printf("BYE BYE\n");
    
  break;
  
  default:
  
  }

} while (op != 7);


  return 0;
}

