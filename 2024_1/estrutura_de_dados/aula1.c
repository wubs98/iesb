#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    struct registro *inicio;
    int qtd;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

void mostrar_lista(lista *l);
lista *cria_lista();
registro *cria_registro();
void inserir_registro(int novo_valor, lista *a);
void menu(lista *l);
void incluir_inicio(lista * l, int valor);

int main(char argc, char *argv[])
{
    lista *a;
    a = cria_lista();
    menu(a);

    return 0;
}

lista *cria_lista()
{
    lista *nova_lista;
    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;
    return nova_lista;
}

registro *cria_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void inserir_registro(int novo_valor, lista *a)
{

    registro *novo, *aux;

    if (a == NULL)
    {
        return;
    }

    novo = cria_registro();
    novo->valor = novo_valor;

    if (a->inicio == NULL)
    {
        a->inicio = novo;
    }
    else
    {
        aux = a->inicio;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    a->qtd++;
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos nessa lista");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\n Valor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void incluir_inicio(lista * l, int valor)
{

    registro * novo;
    novo = cria_registro();
    novo->valor = valor;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else{
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}

void menu(lista *l)
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1 - incluir no inicio lista");
        printf("\n 2 - incluir no final lista");
        printf("\n 3 - Mostrar lista");
        printf("\n 5 - sair");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                printf("\n Digite o numero que deseja inserir:");
                scanf("%d",&numero);
                incluir_inicio(l,numero);
            break;
        case 2:
            printf("\n Digite o numero que deseja inserir:");
            scanf("%d",&numero);
            inserir_registro(numero,l);
            break;
        case 3:
            mostrar_lista(l);
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}