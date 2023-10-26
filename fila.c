#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// CRIA FILA!!!
Fila* fila_criar()
{
    return NULL;
}

int fila_gerar_senha(Fila *l){
    int nova_senha;
    Fila* p = l;

    if (l == NULL){
        nova_senha = 1;
        return nova_senha;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    nova_senha = p->senha + 1;

    return nova_senha;
}


// REMOVE UM NO DA FILA!!
Fila *fila_remover(Fila *l)
{
    Fila *nova;
    if (l == NULL)
    {
        printf("Fila Vazia!!\n");
        return l;
    }
    nova = l->prox;
    free(l);
    return nova;
}

// QUANDO FOR ENCONTRADO UMA MESA VAZIA, CHAMAR ESSA FUNÇÃO PARA TIRAR 4 PESSOAS DA FILA!!
Fila *fila_mesa_encontrada(Fila *l)
{
    Fila *nova;
    if (l->pessoas > 4)
    {
        l->pessoas = l->pessoas - 4;
        printf("Foi encontrado uma mesa para 4 membros do seu grupo!!\n");
        printf("Ainda ficaram %d na Fila de Espera!!\n", l->pessoas);
    }
    else
    {
        nova = fila_remover(l);
        printf("Foi encontrado uma mesa para o seu grupo!!\n");
        return nova;
    }
    return l;
}

//  SENHA UNICA


// INSERE O GRUPO NA FILA!!
Fila *fila_inserir(Fila *l, int senha)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->prox = NULL;
    novo->senha = senha;

    if (l == NULL)
        return novo;
    Fila *p;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

// ADICIONA UM GRUPO E CRIA UMA SENHA
Fila *fila_adicionar_grupo(Fila *l, int tamanho)
{
    Fila *f = l;
    int senha;
    senha = fila_gerar_senha(l);
    f = fila_inserir(l, senha);
    return f;
}

// UM GRUPO ABANDONA A FILA
Fila *fila_abandonar(Fila *l, Fila *grupo, int senha)
{
    Fila *ant = l;
    Fila *p;
    if (l == grupo)
    {
        p = l->prox;
        free(l);
        return p;
        // returno o proximo ou NULL, se for o primeiro elemento!!
    }

    while (ant->prox != grupo)
    {
        ant = ant->prox;
    }

    p = grupo->prox;
    ant->prox = p;
    free(grupo);
    return l;
}

// PROCURA PRIMEIRA PESSOA DO GRUPO NA FILA
Fila *fila_procurar(Fila *l, int senha)
{
    Fila *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->senha == senha)
        {
            return p;
        }
    }
    return NULL;
}

// CHAMA AS FUNCOES PARA REMOVER UM GRUPO DA FILA
Fila *fila_sair(Fila *l)
{
    if (l == NULL)
    {
        printf("Nao existem grupos na fila!!\n");
        return l;
    }
    int senha;
    Fila *grupo;
    printf("Por favor! Digite a senha do grupo:");
    scanf("%d", &senha);
    grupo = fila_procurar(l, senha);

    if (grupo != NULL)
    {
        printf("Seu grupo foi retirado da fila!!\n Voce eh sempre bem-vindo novamente.\n");
        l = fila_abandonar(l, grupo, senha);
    }
    else
    {
        printf("Seu grupo nao foi encontrado na fila!!\n");
    }
    return l;
}

// IMPRIMIR FILA DE ESPERA
void fila_imprimir(Fila *l)
{
    int senha;
    Fila *p;
    if (l == NULL)
    {
        printf("Fila Vazia!!\n");
        return;
    }

    int fila_posicao = 1;

    printf("GRUPOS NA FILA:\n");
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d - Grupo com a Senha:%d\n", fila_posicao, p->senha);
        fila_posicao++;
    }
}

/*
Fila* cria_grupo(Fila* f){
    int tamanho;

    printf("Insira a quantidade de pessoas do seu grupo: ");
    scanf("%d", &tamanho);

    Fila* grupo = (Fila*)malloc(sizeof(Fila));
    grupo->pessoas = tamanho;
    grupo->senha = gera_senha(f);
    grupo->prox = NULL;

    return grupo;
}
*/

/*
Fila* insere_grupo_fila(Fila* f, Fila* grupo){
    Fila* p = f;

    if(f == NULL){
        f = grupo;
        return f;
    }
    
    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = grupo;
    return f;
}
*/
