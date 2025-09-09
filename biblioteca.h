#ifndef Bibliotecas_Include
#define Bibliotecas_Include
#include <stdlib.h>
#include <stdio.h>

/* FUNÇÕES DE MANIPULAÇÃO DE FILA

Fila* CriaFila()                       // CRIA A FILA
int VaziaFila (Fila* f)                // VERIFICA SE A FILA ESTÁ VAZIA
void InsereFila (Fila* f)              // INSERÇÃO (lê Animal com ler_Animal)
void RetiraFila (Fila* f, Fila *r)     // REMOÇÃO (opcionalmente move p/ fila r)
Fila* liberaFila (Fila* f)             // LIBERA A FILA
void imprimeFila (Fila* f)             // IMPRIME A FILA
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

typedef struct nos{
  Animal pets;
  struct nos *prox;
} Nos;

typedef struct fila{
  Nos *ini;
  Nos *fim;
} Fila;


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


  return pets;
}

void imprimir_animal(Animal p){
  printf("Nome: %s\n", p.nome);
  printf("Nascimento: %02d/%02d/%04d\n", p.data.dia, p.data.mes, p.data.ano);
  printf("Espécie: %s\n", p.especie);
  printf("Idade: %d\n", p.idade);
  printf("Prioridade: %s\n", (p.prioridade==0 ? "Emergência" : "Normal"));
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
static Nos* ins_fim (Nos *fim, Animal a){
  Nos *p = (Nos*)malloc(sizeof(Nos));
  if(!p) return fim;        // sem memória: mantém fim antigo
  p->pets = a;
  p->prox = NULL;
  if (fim != NULL)          // se já havia nó no fim, encadeia
    fim->prox = p;
  return p;                 // novo fim da fila
}

void InsereFila (Fila* f){
  if(!f) return;
  Animal a = ler_Animal();
  f->fim = ins_fim(f->fim, a);
  if (f->ini == NULL)       // fila estava vazia
    f->ini = f->fim;
}

static Nos* retira_ini (Nos* ini){
  if(!ini) return NULL;
  Nos* p = ini->prox;
  free(ini);
  return p;
}

void RetiraFila (Fila* f, Fila *r){
  if(VaziaFila(f)){
    printf("Fila vazia.\n");
    return;
  }
  
  Animal a = f->ini->pets;


  f->ini = retira_ini(f->ini);
  if (f->ini == NULL)
    f->fim = NULL;

  if(r){ 
    r->fim = ins_fim(r->fim, a);
    if (r->ini == NULL)
      r->ini = r->fim;
  }else{ 
    printf("\nRemovido:\n");
    imprimir_animal(a);
    printf("\n");
  }
}

void imprimeFila (Fila* f){
  if(VaziaFila(f)){
    printf("\n[Fila vazia]\n");
    return;
  }
  printf("\n--- Fila de Animais ---\n");
  for (Nos* q = f->ini; q != NULL; q = q->prox){
    imprimir_animal(q->pets);
    if(q->prox) printf("-----------------------\n");
  }
  printf("\n");
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

#endif
