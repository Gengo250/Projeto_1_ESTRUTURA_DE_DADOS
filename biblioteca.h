#ifndef Bibliotecas_Include
#define Bibliotecas_Include
#include <stdlib.h>
#include <stdio.h>

/* FUNÇÕES DE MANIPULAÇÃO DE FILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÃO VAZIA RETORNA 1 QUANDO ESTÃO VAZIA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

typedef struct data{
  int dia, mes, ano;
} Data;

typedef struct{
  char nome[50];
  int ID;
  int idade;
  int prioridade;
  char especie[30];
  Data data;
} Animal;

typedef struct nos
{
    Animal pets;
    struct nos *prox;
}Nos;

typedef struct fila
{
    Nos * ini;
    Nos * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Nos *fim, Animal a)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->pets = a;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f)
{

    f->fim = ins_fim(f->fim,ler_Animal());
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

void RetiraFila (Fila* f,Fila *r)
{
    Nos *aux = r->ini;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    InsereFila(r);
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
}

void imprimeFila (Fila* f)
{
    Nos* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->pets);
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    Nos* q = f->ini;
    while (q!=NULL)
    {
        Nos* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}



void limpaTela(){
  system("clear");
}

Animal ler_Animal(){
  Animal pets;

  printf("\nDigite o nome do pet:\n");
  scanf(" %49[^\n]", pets.nome);

  printf("Digite a data de nascimento (dd mm aaaa):\n");
  scanf("%d %d %d", &pets.data.dia, &pets.data.mes, &pets.data.ano);

  printf("Digite a especie do pet: ");
  scanf(" %49[^\n]", &pets.especie);

  printf("Digite a idade do pet: ");
  scanf("%d", &pets.idade);

  printf("Digite a prioridade (0 - Emergencia || 1 - Normal): ");
  scanf("%d", &pets.prioridade);

  return pets;
}

void imprimir_animal(Animal p){
  printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}









#endif 
