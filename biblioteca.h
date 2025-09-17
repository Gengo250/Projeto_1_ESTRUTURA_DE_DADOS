#ifndef Bibliotecas_Include
#define Bibliotecas_Include
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>


typedef struct data{
  int dia, mes, ano;
} Data;

typedef struct animal{
  char nome[50];
  int ID;
  int idade;
  int prioridade;
  char especie[30];
  Data data;
} Animal;

typedef struct nos{
  Animal pets;
  struct nos *prox;
} Nos;

typedef struct fila{
  Nos *ini;
  Nos *fim;
} Fila;

void imprimeRotulo() {
    printf("\n\t\tID   | NOME                 | ESPECIE      | IDADE | NASCIMENTO | PRIORIDADE\n");
    printf("\t\t-----+----------------------+--------------+-----+------------+-----------\n");
}

void imprimeNo(Nos* q) {
    printf("\t\t%4d | %-20.20s | %-12.12s | %3d | %02d/%02d/%04d | %-10s\n",
           q->pets.ID, q->pets.nome, q->pets.especie, q->pets.idade,
           q->pets.data.dia, q->pets.data.mes, q->pets.data.ano,
           (q->pets.prioridade==0 ? "Emergência" : "Normal"));
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

  printf("Digite a especie do pet:\n");
  scanf(" %29[^\n]", pets.especie);

  printf("Digite a idade do pet: ");
  scanf("%d", &pets.idade);

  printf("Digite a prioridade (0 - Emergencia || 1 - Normal): ");
  scanf("%d", &pets.prioridade);

  srand((unsigned)time(NULL));
  pets.ID = 100 + rand() % 900;
  return pets;
}

void imprimir_animal(Animal p){

  printf("\t\t%4d | %-20.20s | %-12.12s | %3d | %02d/%02d/%04d | %-10s\n",
         p.ID, p.nome, p.especie, p.idade,
         p.data.dia, p.data.mes, p.data.ano,
         (p.prioridade==0 ? "Emergência" : "Normal"));
}

int VaziaFila (Fila* f){
  return (f == NULL || f->ini == NULL) ? 1 : 0;
}

Fila* CriaFila (){
  Fila* f = (Fila*) malloc(sizeof(Fila));
  if(!f) return NULL;
  f->ini = f->fim = NULL;
  return f;
}

/* insere nó no fim, devolvendo o novo ponteiro fim */
 Nos* ins_fim (Nos *fim, Animal a){
  Nos *p = (Nos*)malloc(sizeof(Nos));
  p->pets = a;
  p->prox = NULL;
  if (fim != NULL)          // se já havia nó no fim, encadeia
    fim->prox = p;
  return p;                 // novo fim da fila
}

void InsereFila (Fila* f, Fila *p){
  if(!f) return;
  if(!p) return;
  Animal a = ler_Animal();
  if(a.prioridade == 0){    //Fila f = emergencia
      f->fim = ins_fim(f->fim, a);
  if (f->ini == NULL)       // fila estava vazia
    f->ini = f->fim;
  }
  else if(a.prioridade == 1){ //Fila p = Normal
      p->fim = ins_fim(p->fim, a);
  if (p->ini == NULL)       // fila estava vazia
    p->ini = p->fim;
  }

  printf("\n\t\tPet cadastrado com sucesso!\n\n");

}

 Nos* retira_ini (Nos* ini){
  Nos* p = ini->prox;
  free(ini);
  return p;
}



Fila* liberaFila (Fila* f){
  if(!f) return NULL;
  Nos* q = f->ini;
  while (q != NULL){
    Nos* t = q->prox;
    free(q);
    q = t;
  }
  free(f);
  return NULL;
}

Animal RetiraElemento (Fila* f)
{
    Animal v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
    }
    v = f->ini->pets;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void Teste (Fila *emer, Fila* norm, Fila* remo) {
    Fila * aux;
    aux = norm;
    if (emer->fim!=NULL) {
        aux = emer;
    }

    Animal a = RetiraElemento(aux);
    if(remo != NULL){
        remo->fim = ins_fim(remo->fim, a);
        if (remo->ini == NULL){
            remo->ini = remo->fim;
        }
    }

    if (emer!=NULL) {
        emer = aux;
    }
    else{
        norm = aux;
    }
   printf("\n Pet %s foi atendido com sucesso!\n", a.nome);
}


void imprimeFila (Fila* f){
  if (VaziaFila(f)){
    printf("\n[Fila vazia]\n\n");
    return;
  }

  imprimeRotulo();
  for (Nos* q = f->ini; q != NULL; q = q->prox){
    imprimeNo(q);
  }

  printf("\n");
}


Fila * procuraID (Fila * emer, Fila * norm, Fila * remo , int id) {
    Nos* aux;
    aux = emer -> ini;

   
     while(aux != NULL) {
        if (aux->pets.ID == id) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Não\n");
                break;
        }else {
          printf("\nID não existe\n");
        }
        aux = aux -> prox;
    }
    aux = norm -> ini;
    while(aux != NULL) {
        if (aux->pets.ID == id) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Não\n");
                break;
        } else {
          printf("\nID não existe\n");
        }
        aux = aux -> prox;
    }
    aux = remo -> ini;
    while(aux != NULL) {
        if (aux->pets.ID == id) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Sim\n");
                break;
        } else {
          printf("\nID não existe\n");
        }
        aux = aux -> prox;
     }
    
    
}
Fila * procuraNome (Fila * emer, Fila * norm, Fila * remo , char *nome) {
    Nos* aux;
    aux = emer -> ini;

   
     while(aux != NULL) {
        if (strcmp(aux->pets.nome, nome) == 0) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Não\n");
                break;
        }else {
          printf("\nNome não existe\n");
        }
        aux = aux -> prox;
    }
    aux = norm -> ini;
    while(aux != NULL) {
        if (strcmp(aux->pets.nome, nome) == 0) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Não\n");
                break;
        } else {
          printf("\nNome não existe\n");
        }
        aux = aux -> prox;
    }
    aux = remo -> ini;
    while(aux != NULL) {
        if (strcmp(aux->pets.nome, nome) == 0) {
                imprimeRotulo();
                imprimeNo(aux);
                printf("\nJá foi atendido? - Sim\n");
                break;
        } else {
          printf("\nNome não existe\n");
        }
        aux = aux -> prox;
     }
    
    
}


#endif