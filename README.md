<!--
README.md — Projeto: Gerenciamento de Atendimento em Clínica Veterinária (Estruturas de Dados)
Autor: Miguel de Castilho Gengo (Gengo250)
-->

<!-- ============================== -->
<!--           BANNERS             -->
<!-- ============================== -->

<!-- Banner para modo ESCURO -->
<p align="center">
  <img src="assets/banners/header-dark.png#gh-dark-mode-only" alt="Banner do Projeto — Modo Escuro" width="100%">
</p>

<!-- Banner para modo CLARO -->
<p align="center">
  <img src="assets/banners/header-light.png#gh-light-mode-only" alt="Banner do Projeto — Modo Claro" width="100%">
</p>

<!-- Badges (exemplos, ajuste conforme seu setup) -->
<p align="center">
  <a href="#"><img alt="C Language" src="https://img.shields.io/badge/lang-C-blue.svg"></a>
  <a href="#"><img alt="Build" src="https://img.shields.io/badge/build-gcc-success"></a>
  <a href="#"><img alt="License" src="https://img.shields.io/badge/license-MIT-green"></a>
  <a href="#"><img alt="OS" src="https://img.shields.io/badge/OS-Linux%20%7C%20Windows%20%7C%20macOS-informational"></a>
</p>

<h1 align="center">Gerenciamento de Atendimento em Clínica Veterinária</h1>
<p align="center"><em>Projeto prático de Estruturas de Dados em C (filas, ponteiros e memória dinâmica) com ênfase em priorização por emergência.</em></p>

---

## 📑 Sumário
- [1. Resumo](#1-resumo)
- [2. Contexto Acadêmico](#2-contexto-acadêmico)
- [3. Objetivos](#3-objetivos)
- [4. Fundamentação Teórica](#4-fundamentação-teórica)
  - [4.1. Filas (Queues)](#41-filas-queues)
  - [4.2. Listas Encadeadas e Nós](#42-listas-encadeadas-e-nós)
  - [4.3. Ponteiros e Memória Dinâmica](#43-ponteiros-e-memória-dinâmica)
  - [4.4. Geração de Números Aleatórios e Semente](#44-geração-de-números-aleatórios-e-semente)
  - [4.5. Internacionalização (locale)](#45-internacionalização-locale)
- [5. Requisitos Funcionais](#5-requisitos-funcionais)
- [6. Arquitetura do Código](#6-arquitetura-do-código)
  - [6.1. Arquivo `biblioteca.h`](#61-arquivo-bibliotecah)
  - [6.2. Arquivo `main.c`](#62-arquivo-mainc)
- [7. Estruturas de Dados](#7-estruturas-de-dados)
- [8. Principais Operações e Complexidade](#8-principais-operações-e-complexidade)
- [9. Fluxo de Execução (Visão de Uso)](#9-fluxo-de-execução-visão-de-uso)
- [10. Geração de IDs Únicos (100–999)](#10-geração-de-ids-únicos-100–999)
- [11. Compilação e Execução](#11-compilação-e-execução)
- [12. Testes e Casos de Uso](#12-testes-e-casos-de-uso)
- [13. Organização do Repositório](#13-organização-do-repositório)
- [14. Boas Práticas e Qualidade](#14-boas-práticas-e-qualidade)
- [15. Limitações e Trabalhos Futuros](#15-limitações-e-trabalhos-futuros)
- [16. Licença](#16-licença)
- [17. Agradecimentos](#17-agradecimentos)

---

## 1. Resumo
Este repositório implementa, em **C**, um sistema de **fila de atendimento** para uma **clínica veterinária**, priorizando **emergências**. O projeto exercita **manipulação dinâmica de memória**, **ponteiros**, **listas encadeadas** e **filas**, além de **geração de números aleatórios** com **IDs únicos** para cada pet.  
Há **duas filas** principais (Emergência e Normal) e uma estrutura para **Registros Atendidos**. O usuário interage por **menu textual**, e o sistema provê funcionalidades de **inserção**, **atendimento**, **busca** e **relatórios**.

---

## 2. Contexto Acadêmico
- **Curso:** Engenharia de Computação  
- **Componente Curricular:** Estruturas de Dados (Prática)  
- **Tema:** Filas, ponteiros, memória dinâmica e geração de números aleatórios em C  
- **Entrega:** Código-fonte em C e relatório (este README segue formato de **relatório universitário**)

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

### 6.1. Arquivo `biblioteca.h`
- **Includes** esperados: `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<locale.h>`, `<string.h>`.  
- **Tipos (sugestivo)**:
  - `Data { int dia, mes, ano; }`
  - `Animal { int id; char nome[51]; char especie[31]; int idade; Data nasc; int prioridade; /* 0=Emerg, 1=Normal */ }`
  - `Nos { Animal pets; struct nos *prox; }`
  - `Fila { Nos *ini, *fim; }`
- **Protótipos usuais**:
  - `Fila* CriaFila(void);`
  - `int VaziaFila(Fila* f);`
  - `void InsereFila(Fila* f, Animal a);`
  - `int  RetiraFila(Fila* f, Animal* out);`
  - `Fila* liberaFila(Fila* f);`
  - `void imprimeFila(Fila* f);`
  - Utilitários: `imprimeRotulo()`, `imprimeNo(Nos*)`, `geraIDUnico(...)`, `procuraNome(...)` / `procuraID(...)`.

> Observação: ajuste esta lista para refletir exatamente suas assinaturas atuais.

### 6.2. Arquivo `main.c`
- **Inicialização** de locale/semente (quando aplicável).  
- Criação das filas: `Normal`, `Emergencia`, `Removidos/Atendidos`.  
- Laço principal com **menu** e **opções 1–7**, encerrando com `do { ... } while (op != 7);`  
- Encaminhamento das opções para funções de **cadastro**, **atendimento**, **busca** e **relatório**.

---

## 7. Estruturas de Dados
```c
typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  int  id;                 // 100-999 (único)
  char nome[51];           // até 50 chars
  char especie[31];        // "cachorro", "gato", etc.
  int  idade;
  Data nasc;
  int  prioridade;         // 0=Emergência, 1=Normal
} Animal;

typedef struct nos{
  Animal     pets;
  struct nos *prox;
} Nos;

typedef struct fila{
  Nos *ini;
  Nos *fim;
} Fila;
```

---

## 8. Principais Operações e Complexidade

| Operação                       | Descrição                                              | Complexidade |
|--------------------------------|--------------------------------------------------------|--------------|
| `CriaFila`                     | Inicializa ponteiros `ini=fim=NULL`.                  | O(1)         |
| `VaziaFila`                    | Retorna `ini==NULL`.                                   | O(1)         |
| `InsereFila` (enqueue)         | Insere nó no **fim** usando ponteiro `fim`.           | O(1)         |
| `RetiraFila` (dequeue)         | Remove nó do **início** e ajusta `ini`.               | O(1)         |
| `imprimeFila`                  | Percorre nós e imprime campos.                         | O(n)         |
| `procuraNome` / `procuraID`    | Busca linear nos nós (ambas filas, e/ou atendidos).   | O(n)         |
| `geraIDUnico`                  | Depende da estratégia (ver §10).                      | O(1) a O(k)  |

---

## 9. Fluxo de Execução (Visão de Uso)

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

## 10. Geração de IDs Únicos (100–999)

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

## 11. Compilação e Execução

### Linux (gcc)
```bash
gcc main.c -o clinic -Wall -Wextra -O2
./clinic
```

### Windows (MinGW)
```bash
gcc main.c -o clinic.exe -Wall -Wextra -O2
clinic.exe
```

> **Observação:** Se separar em múltiplos `.c/.h`, lembre-se de compilar todos os arquivos:
> `gcc main.c fila.c utils.c -o clinic -Wall -Wextra -O2`

---

## 12. Testes e Casos de Uso

- **Inserção em lote**: cadastrar 10+ pets com prioridades variadas.  
- **Atendimento com prioridade**: verificar que **Emergência** sempre é atendida **antes**.  
- **Busca por nome**: inserir nomes repetidos e confirmar **impressão de todos**.  
- **ID único**: tentar forçar colisões e inspecionar a **tabela de vistos**.  
- **Relatórios**: conferir formatos e **alinhamento** das colunas.  
- **Robustez de entrada**: validar inteiros, strings e datas (limites de tamanho e faixa).

> **Ferramentas úteis (Linux):**  
> - *Valgrind*: `valgrind --leak-check=full ./clinic` para checar vazamentos.  
> - *AddressSanitizer*: `-fsanitize=address -fno-omit-frame-pointer` na compilação.

---

## 13. Organização do Repositório
```
.
├── main.c
├── biblioteca.h
├── assets/
│   └── banners/
│       ├── header-dark.png     # sugerido: 1600×380 px | tema escuro
│       └── header-light.png    # sugerido: 1600×380 px | tema claro
└── README.md
```

---

## 14. Boas Práticas e Qualidade
- **Checagem de erros**: toda alocação (`malloc`) deve ser verificada.  
- **Encapsulamento**: funções para entrada/validação (`ler_Animal`, `validaData`, etc.).  
- **Saída formatada**: padronizar `imprimeRotulo()` e `imprimeNo()`; largura fixa de colunas.  
- **Warnings zero**: compilar com `-Wall -Wextra` e resolver avisos.  
- **Liberação de memória**: `liberaFila()` varrendo nós com `free`.  
- **Estilo**: nomes consistentes, comentários sucintos, responsabilidades claras por função.

---

## 15. Limitações e Trabalhos Futuros
- **Persistência**: atualmente em memória — pode-se incluir **salvar/carregar** em arquivo.  
- **Datas e validação robusta**: tratar meses de 30/31 dias e anos bissextos com mais rigor.  
- **Relatórios avançados**: exportar para **CSV**/**JSON**; filtros por espécie/idade.  
- **Métricas**: tempo médio de espera, contagem por prioridade, histórico por dia.  
- **Interface**: migrar para **UI** (ncurses) ou **front-end** simples com **sockets**.

---

## 16. Licença
Este projeto é distribuído sob a licença **MIT**. Consulte o arquivo `LICENSE` (opcional).

---

## 17. Agradecimentos
- Professores e monitores da disciplina de **Estruturas de Dados**.  
- Colegas de time pelo esforço conjunto e revisão de código.

---

<!-- Rodapé com mini banner opcional -->
<p align="center">
  <img src="assets/banners/footer-strip.png" alt="Rodapé" width="60%">
</p>
