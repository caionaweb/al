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

typedef struct queue *Queue;
struct queue {
    int vector[ MAX_LENGHT ];
    int length;
};

Queue create();

void destruct( Queue queue );

void dump( Queue queue );

int enqueue( Queue queue, int item );

int desenqueue( Queue queue );

int is_empty( Queue queue );

int lenght( Queue queue );

void print_queue( Queue queue );


/*
    Testando as funções
*/
int main()
{
    setlocale( LC_ALL, "portuguese" );
    printf( "Testando fila estática...\n" );
    printf( "----------------------------------------------\n" );

    printf( "Criando a fila estática...\n" );
    Queue fila = create();
    printf( "feito!\n" );

    printf( "Comprimento da fila: %d\n", lenght( fila ) );

    printf( "Imprimindo a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );

    printf( "Enfileirando alguns elementos na fila...\n" );
    enqueue( fila, 10 );
    enqueue( fila, 20 );
    enqueue( fila, 30 );
    enqueue( fila, 40 );
    enqueue( fila, 50 );
    enqueue( fila, 60 );
    printf( "feito!\n" );

    printf( "Comprimento da fila: %d\n", lenght( fila ) );

    printf( "Imprimindo a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );

    printf( "Desenfileirando dois elementos da fila...\n" );
    printf( "%d\n", desenqueue( fila ) );
    printf( "%d\n", desenqueue( fila ) );

    printf( "Imprimindo a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );

    printf( "Comprimento da fila: %d\n", lenght( fila ) );

    printf( "Comprimento a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );

    printf( "Enfileirando alguns elementos na fila...\n" );
    enqueue( fila, 44 );
    printf( "feito!\n" );

    printf( "Comprimento da fila: %d\n", lenght( fila ) );

    printf( "Imprimindo a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );


    printf( "Esvaziando a fila...\n" );
    dump( fila );
    printf( "feito!\n" );

    printf( "Comprimento da fila: %d\n", lenght( fila ) );

    printf( "Imprimindo a fila...\n" );
    print_queue( fila );
    printf( "feito!\n" );

    printf( "destruindo a fila...\n" );
    destruct( fila );
    printf( "feito!\n" );

    printf( "\n----------------------------------------------\n" );
    printf( "------------------Fim dos Testes ---------------\n" );
    return 0;
}


/*
    Implementando as funções
*/

Queue create()
{
    Queue queue = ( Queue ) malloc( sizeof( struct queue ) );
    queue->length = 0;

    return queue;
}

void destruct( Queue queue )
{
    if( queue ) free( queue );
}

void dump( Queue queue )
{
    free( queue );
    queue = create();
}

int enqueue( Queue queue, int item )
{
    if ( !queue || queue->length == MAX_LENGHT )
        return false;

    queue->vector[ queue->length ] = item;
    queue->length++;

    return true;
}

int desenqueue( Queue queue )
{
    if ( queue && queue->length > 0 ) {
        int value = queue->vector[ 0 ];
        queue->length--;
        int j;
        for ( j = 0; j < queue->length ; j++ ) {
            queue->vector[ j ] = queue->vector[ j + 1 ];
        }
        return value;
    }
    return false;
}

int is_empty( Queue queue )
{
    return ( queue->length == 0 );

}

int lenght( Queue queue )
{
    if ( !queue )
        return false;

    return queue->length;
}

void print_queue( Queue queue )
{
    if ( !queue ) {
        printf( "Fila não inicializada ou destruída\n" );
    }
    else if ( queue->length == 0 ) {
        printf( "Fila vazia\n" );
    }
    else {
        int j;
        for ( j = 0; j < queue->length; j++ ) {
            printf( "%d ", queue->vector[ j ] );
        }
        printf( "\n" );
    }
}
