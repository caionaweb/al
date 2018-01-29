#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define true 1
#define false 0

#define MAX_LENGHT 250

typedef struct node Node;
struct node {
    int value;
    Node *next;
};

typedef struct stack *Stack;
struct stack {
    int vector[ MAX_LENGHT ];
    int length;
};

Stack create();

void destruct( Stack stack );

void dump( Stack stack );

int push( Stack, int item );

int pop( Stack );

int top( Stack, int item );

int peek( Stack, int item );

int is_empty( Stack stack );

int hight( Stack stack );

void print_stack( Stack stack );


/*
    Testando as funções
*/
int main()
{
    setlocale( LC_ALL, "portuguese" );
    printf( "Testando Pilha estática...\n" );
    printf( "----------------------------------------------\n" );

    printf( "Criando a pilha estática...\n" );
    Stack pilha = create();
    printf( "feito!\n" );

    printf( "Altura da pilha: %d\n", hight( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );

    printf( "Empilhando alguns elementos na pilha...\n" );
    push( pilha, 10 );
    push( pilha, 20 );
    push( pilha, 30 );
    push( pilha, 40 );
    push( pilha, 50 );
    push( pilha, 60 );
    push( pilha, 70 );
    printf( "feito!\n" );

    printf( "Altura da pilha: %d\n", hight( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );

    printf( "Desempilhando dois elementos da pilha...\n" );
    printf( "%d\n", pop( pilha ) );
    printf( "%d\n", pop( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );

    printf( "Altura da pilha: %d\n", hight( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );

    printf( "Empilhando alguns elementos na pilha...\n" );
    push( pilha, 0 );
    printf( "feito!\n" );

    printf( "Altura da pilha: %d\n", hight( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );


    printf( "Esvaziando a pilha...\n" );
    dump( pilha );
    printf( "feito!\n" );

    printf( "Altura da pilha: %d\n", hight( pilha ) );

    printf( "Imprimindo a pilha...\n" );
    print_stack( pilha );
    printf( "feito!\n" );

    printf( "destruindo a pilha...\n" );
    destruct( pilha );
    printf( "feito!\n" );

    printf( "\n----------------------------------------------\n" );
    printf( "------------------Fim dos Testes ---------------\n" );
    return 0;
}


/*
    Implementando as funções as funções
*/

Stack create()
{
    Stack stack = ( Stack ) malloc( sizeof( struct stack ) );
    stack->length = 0;

    return stack;
}

void destruct( Stack stack )
{
    if ( stack ) {
        free( stack );
    }
}

void dump( Stack stack )
{
    if ( stack ) {
        stack->length = 0;
        //free(  stack );
        stack = ( Stack ) malloc( sizeof( struct stack ) );
    }
}

int push( Stack stack, int item )
{
    if ( stack->length == MAX_LENGHT )
        return false;

    stack->vector[ stack->length ] = item;
    stack->length++;

    return true;
}

int pop( Stack stack )
{
    int value = stack->vector[ stack->length - 1 ];
    stack->length--;

    return value;
}

int top( Stack stack, int item )
{
    return stack->vector[ stack->length - 1 ];
}

int peek( Stack stack, int item )
{
    return stack->vector[ stack->length - 1 ];
}

int is_empty( Stack stack )
{
    return stack->length;
}

int hight( Stack stack )
{
    if ( !stack )
        return -1;

    return stack->length;
}

void print_stack( Stack stack )
{
    if ( !stack ) {
        printf( "pilha não inicializada\n" );
    }
    else if ( stack->length == 0 ) {
        printf( "pilha vazia\n" );
    }
    else {
        int j;
        for ( j = stack->length - 1; j >= 0; j-- ) {
            printf( "%d ", stack->vector[ j ] );
        }
        printf( "\n" );
    }
}
