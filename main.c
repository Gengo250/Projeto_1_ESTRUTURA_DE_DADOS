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
    
    printf("+--------------------------------------------------------------+\n");
    printf("| %-60s |\n","        MENU DE ATENDIMENTO AO SEU PET");
    printf("| %-60s |\n", "");
    printf("| %-60s |\n", " 1 - Cadastrar um Pet");
    printf("| %-60s |\n", " 2 - Atender um Pet");
    printf("| %-60s |\n", " 3 - Buscar um Pet");
    printf("| %-60s |\n", " 4 - Imprimir Relatorio com todos os pets");
    printf("| %-60s |\n", " 5 - Imprimir proximos pets atendidos");
    printf("| %-60s |\n", " 6 - Imprimir todos os pets ja atendidos");
    printf("| %-60s |\n", " 7 - Sair");
    printf("+--------------------------------------------------------------+\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);

    //limpaTela();

  switch (op)
  {

  case 1:

    InsereFila(Emergencia, Normal);
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
    printf("\t\t\n\nOBRIGADO POR ESCOLHER NOSSO ATENDIMENTO\n");
    
  break;
  
  default:
  printf("\n\n\tOpção inválida! Por favor insira valore corretos\t\n\n");
  break; 
  
  }

} while (op != 7);


  return 0;
}

