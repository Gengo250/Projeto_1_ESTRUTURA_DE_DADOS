<!--
README.md — Projeto: Gerenciamento de Atendimento em Clínica Veterinária (Estruturas de Dados)
Autor: Miguel de Castilho Gengo (Gengo250)
-->

<!-- ============================== -->
<!--           BANNERS             -->
<!-- ============================== -->

<!-- Badges (exemplos, ajuste conforme seu setup) -->
<p align="center">
  <a href="#"><img alt="C Language" src="https://img.shields.io/badge/lang-C-blue.svg"></a>
  <a href="#"><img alt="Build" src="https://img.shields.io/badge/build-gcc-success"></a>
  <a href="#"><img alt="License" src="https://img.shields.io/badge/license-MIT-green"></a>
  <a href="#"><img alt="OS" src="https://img.shields.io/badge/OS-Linux%20%7C%20Windows%20%7C%20macOS-informational"></a>
</p>

<h1 align="center">Gerenciamento de Atendimento em Clínica Veterinária</h1>
<p align="center"><em>Projeto prático de Estruturas de Dados em C (filas, ponteiros e memória dinâmica) com ênfase em priorização por emergência.</em></p>

<!-- Alternativa com badges (opcional) -->
## ✍️ AUTORES DO PROJETO
<p align="center">
  <a href="https://github.com/Gengo250"><img alt="Gengo250" src="https://img.shields.io/badge/GitHub-Gengo250-181717?logo=github"></a>
  &nbsp;
  <a href="https://github.com/danielwu05"><img alt="danielwu05" src="https://img.shields.io/badge/GitHub-danielwu05-181717?logo=github"></a>
  &nbsp;
  <a href="https://github.com/LuccasZibordi"><img alt="LuccasZibordi" src="https://img.shields.io/badge/GitHub-LuccasZibordi-181717?logo=github"></a>
</p>

---

## 1. Resumo
Este repositório implementa, em **C**, um sistema de **fila de atendimento** para uma **clínica veterinária**, priorizando **emergências**. O projeto exercita **manipulação dinâmica de memória**, **ponteiros**, **listas encadeadas** e **filas**, além de **geração de números aleatórios** com **IDs únicos** para cada pet.  
Há **duas filas** principais (Emergência e Normal) e uma estrutura para **Registros Atendidos**. O usuário interage por **menu textual**, e o sistema provê funcionalidades de **inserção**, **atendimento**, **busca** e **relatórios**.

---

## 2. Contexto Acadêmico
- **Curso:** Engenharia de Computação  
- **Componente Curricular:** Estruturas de Dados (Prática)  
- **Tema:** Filas, ponteiros, memória dinâmica e geração de números aleatórios em C  
- **Entrega:** Código-fonte em C e relatório 

---

## 3. Objetivos
- Modelar duas **filas** (Emergência e Normal) com **prioridade de atendimento**.  
- Garantir **IDs únicos** no intervalo **[100, 999]**.  
- Implementar **operações essenciais** sobre filas: inserir, retirar, imprimir, buscar.  
- Exercitar **teoria e prática** de **ponteiros** e **alocação dinâmica** (`malloc/free`).  
- Organizar e documentar o projeto de forma **profissional** e **auditável**.

---

## 4. Fundamentação Teórica

### 4.1. Filas (Queues)
Filas são estruturas **FIFO** (*First-In, First-Out*). A inserção ocorre no **fim** (*enqueue*) e a remoção no **início** (*dequeue*).  
- **Motivação:** Processos de **atendimento** real, como clínicas, bancos e sistemas de impressão.  
- **Prioridades:** Quando há classes de prioridade (ex.: **Emergência** > **Normal**), a política de remoção verifica **primeiro** a fila prioritária.

### 4.2. Listas Encadeadas e Nós
Cada elemento da fila é armazenado em um **nó** com ponteiro para o **próximo**.  
- **Vantagens:** Inserção/remoção **O(1)** nas extremidades; tamanho **dinâmico**.  
- **Cuidado:** **Gerenciamento de memória** explícito (alocar e liberar corretamente).

### 4.3. Ponteiros e Memória Dinâmica
- **Ponteiros** acessam endereços de memória; são fundamentais para **listas encadeadas**.  
- Em C, usamos `malloc`/`free` (e checagem de `NULL`).  
- **Erros comuns:** *memory leaks*, *dangling pointers*, dupla liberação.  
- **Boas práticas:** Inicializar ponteiros, verificar retorno de `malloc`, projetar funções de **limpeza**.

### 4.4. Geração de Números Aleatórios e Semente
- `rand()` gera pseudoaleatórios; `srand(seed)` define a **semente**.  
- **Uso típico:** `srand(time(NULL));` para variar a sequência.  
- **IDs únicos:** além de `rand()`, é necessário **garantir unicidade** (tabela de vistos, tentativa-repetição, etc.).

### 4.5. Internacionalização (locale)
- O projeto pode utilizar `setlocale(LC_ALL, "Portuguese");` para acentuação/formatos compatíveis com PT-BR no terminal.

---

## 5. Requisitos Funcionais
1. **Inserir** um pet (decidir fila **Emergência** ou **Normal**; gerar **ID único**; coletar dados).  
2. **Atender** pet (remover da fila, priorizando **Emergência**; registrar atendimento; **imprimir dados**).  
3. **Buscar** pet por **nome** e/ou **ID** (indicar se já foi atendido).  
4. **Relatório**: imprimir todos os pets em **ambas as filas** no formato  
   `ID | Nome | Espécie | Idade | Data de Nascimento | Prioridade`.  
5. **Próximo** a ser atendido: mostrar `Nome | Espécie | Tipo (Emergência/Normal)`.  
6. **Atendidos**: imprimir na **ordem de atendimento**.  
7. **Finalizar** o sistema (opção **Sair** no menu).

---

## 6. Arquitetura do Código

### 6.1. Arquivo `biblioteca.h` (atualizado)

**Includes utilizados:** `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<locale.h>`, `<string.h>`

**Definições de tipos (exatas do código):**
```c
typedef struct data{
  int dia, mes, ano;
} Data;

typedef struct{
  char nome[50];
  int  ID;
  int  idade;
  int  prioridade;   /* 0 = Emergência | 1 = Normal */
  char especie[30];
  Data data;         /* Data de nascimento */
} Animal;

typedef struct nos{
  Animal      pets;
  struct nos *prox;
} Nos;

typedef struct fila{
  Nos *ini;
  Nos *fim;
} Fila;
```

**Funções implementadas (assinaturas atuais):**
```c
/* Impressão formatada */
void  imprimeRotulo(void);
void  imprimeNo(Nos *q);

/* Utilitários de E/S e UI */
void    limpaTela(void);
Animal  ler_Animal(void);
void    imprimir_animal(Animal p);

/* Operações de fila */
int    VaziaFila(Fila *f);
Fila*  CriaFila(void);
Nos*   ins_fim(Nos *fim, Animal a);   /* insere nó no fim e retorna o novo fim */
void   InsereFila(Fila *f, Fila *p);  /* lê Animal e enfileira em Emergência (f) ou Normal (p) */

/* Remoção (nível de nó e nível de fila) */
Nos*   retira_ini(Nos *ini);
Fila*  liberaFila(Fila *f);
Animal RetiraElemento(Fila *f);

/* Rotina de atendimento e registro */
void   Teste(Fila *emer, Fila *norm, Fila *remo);

/* Impressão */
void   imprimeFila(Fila *f);

/* Buscas */
Fila*  procuraID   (Fila *emer, Fila *norm, Fila *remo, int   id);
Fila*  procuraNome (Fila *emer, Fila *norm, Fila *remo, char *nome);
```

**Comportamento e contratos (resumo):**
- `InsereFila(f, p)`: lê um `Animal` via `ler_Animal()`. Se `prioridade==0`, enfileira em **Emergência** (`f`); se `prioridade==1`, enfileira em **Normal** (`p`).  
- `ins_fim(fim, a)`: aloca nó, encadeia ao último (se existir) e **retorna o novo ponteiro `fim`**.  
- `retira_ini(ini)`: desaloca o primeiro nó e **retorna o novo início**.  
- `RetiraElemento(f)`: remove do **início** da fila `f` e devolve o `Animal`.  
- `Teste(emer, norm, remo)`: escolhe a fila não vazia (prefere **Emergência**), remove um `Animal` e, se `remo` for não nula, armazena-o como **atendido**.  
- `imprimeFila(f)`: imprime cabeçalho e percorre todos os nós.  
- `liberaFila(f)`: libera **todos os nós** e a própria fila.  
- `procuraID` / `procuraNome`: procuram sequencialmente em **Emergência**, **Normal** e **Removidos**, imprimem o registro quando encontrado e informam se já foi atendido.


## 7. Fluxo de Execução (Visão de Uso)

1) **Inserir Pet**  
- Ler dados + gerar **ID único**.  
- Decide **prioridade** (0=Emergência, 1=Normal).  
- Enfileira em `Emergencia` **ou** `Normal`.  

2) **Atender Pet**  
- Se `Emergencia` **não vazia**, `dequeue(Emergencia)`; senão `dequeue(Normal)`.  
- Acrescenta animal atendido em `Removidos/Atendidos`.  
- Imprime dados formatados (`imprimeRotulo` + `imprimeNo`).  

3) **Buscar**  
- Por **ID** (único, retorno imediato) ou por **Nome** (pode haver múltiplos).  
- Indica se **já foi atendido** ou não.  

4) **Relatórios**  
- Imprime **todas** as filas no formato solicitado;  
- Exibe **próximo** a ser atendido;  
- Lista **atendidos** na ordem cronológica.

---

## 8. Geração de IDs Únicos (100–999)

**Exigência:** ID aleatório no intervalo **[100, 999]** e **não repetido**.

**Estratégias recomendadas:**
- **Tabela de vistos (bool seen[1000])**:  
  - Inicialize tudo como `false`.  
  - Ao gerar um ID, se `seen[id]==false`, marque `true` e use.  
  - **O(1)** por verificação; simples e eficiente.
- **Rejeição por colisão:**  
  - Gere e re-tente enquanto o ID já existir na estrutura (busca nas filas + atendidos).  
  - **Custo** cresce com ocupação.

**Semente:**
```c
#include <time.h>
srand((unsigned)time(NULL)); // uma vez, no início do programa
```

---

## 9. Organização do Repositório
```
.
├── main.c
├── biblioteca.h
└── README.md
```


---

## 11. Agradecimentos
- Professora Lúcia da disciplina de **Estruturas de Dados**.  
- Colegas de time pelo esforço conjunto e revisão de código.



---
