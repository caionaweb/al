#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"

// Cria uma lista estática com MAX_LENGTH de espaços
StaticList static_list_build() {
    StaticList list = ( StaticList ) malloc( sizeof( struct static_list ) );
    if ( list != NULL )
        list->lenght = 0;

    return list;
}

// destroi a lista estática
void static_list_destruct( StaticList list ) {
    free( list );
}

// esvazia a lista estática
void static_list_dump(  StaticList list ) {
    int i = 0;
    while ( i < MAX_LENGTH ) {
        list->slots[ i ].numericKey = ( int )NULL;
        list->slots[ i ].value[ 0 ] = '\0';
        list->lenght--;
        i++;
    }
}

// insere um item no final da lista
int static_list_insert_end( StaticList list, U_TYPE item ) {
    if ( list == NULL )
        return false;
    if ( list->lenght == MAX_LENGTH )
        return false;

    list->slots[ list->lenght ] = item;
    list->lenght++;

    return true;
}

// insere um item no inicio da lista
int static_list_insert_begin( StaticList list, U_TYPE item ){
    if ( list == NULL )
        return false;
    if ( list->lenght == MAX_LENGTH )
        return false;

    int i;
    for ( i = 1; i < MAX_LENGTH; i++ ) {
        list->slots[ i + 1 ] = list->slots[ i ];
    }

    list->slots[ 0 ] = item;
    list->lenght++;

    return true;
}

int static_list_insert_ordered_item( StaticList list, U_TYPE item ){
    if ( list = NULL || list->lenght == MAX_LENGTH )
        return false;

    int i = 0;
    while( (i < list->lenght ) || item.numericKey > list->slots[ i ].numericKey ) i++;

    int j;
    for ( j = list->lenght - 1; j >= i; j-- )
        list->slots[ j + 1] = list->slots[ j ]

    list->slots[ i ] = item;
    list->lenght++;

    return true;
}

// remove o último item da lista
int static_list_remove_item_end( StaticList list ) {
    if ( list == NULL )
        return false;
    if ( list->lenght == 0 )
        return false;

    list->lenght--;

    return true;
}

// remove o primeiro item da lista
int static_list_remove_item_begin( StaticList list ) {
    if ( list == NULL )
        return false;
    if ( list->lenght == 0 )
        return false;

    int i;
    for ( i = 0; i < list->lenght - 1; i++ ) {
        list->slots[ i ] = list->slots[ i + 1 ];
    }

    list->lenght--;

    return true;
}

// remove um item baseado numa chave numérica
int static_list_remove_item( StaticList list, int numericKey ) {
    if ( list == NULL )
        return false;
    if ( list->lenght == 0 )
        return false;

    int i = 0;
    while( i < list->lenght && list->slots[ i ].numericKey != numericKey )
        i++;

    if ( i == list->lenght )
        return false;

    int j;
    for ( j = i; j < list->lenght; j++ ) {
        list->slots[ j ] = list->slots[ j + 1 ];
    }

    list->lenght--;

    return true;
}

// retorna comprimento da lista
int static_list_get_lenght( StaticList list ) {
    if( list == NULL )
        return -666; // well... just a jocke lol

    return list->lenght;
}

// retorna true se a lista estiver vazia
int static_list_is_empty( StaticList list ){
    if( list == NULL )
        return -666;

    return ( list->lenght == 0 );
}

// retorna true se a lista estiver cheia
int static_list_is_full( StaticList list ){
    if( list == NULL )
        return -666;

    return ( list->lenght == MAX_LENGTH );
}

// imprime uma lista estática
void static_list_print( StaticList list ){
    if ( list == NULL ) {
        printf( "Lista inválida.\n" );
    }
    else if( list->lenght == 0 ) {
        printf( "Lista vazia.\n" );
    }
    else {
        printf( "Imprimindo lista criada...\n" );
        int i;
        for ( i = 0; i < MAX_LENGTH; i++) {
            printf( "Chave numérica de %d: %d \n", i + 1, list->slots[ i ].numericKey );
            printf( "valor associado a chave numérica de numero %d: %s \n", i + 1, list->slots[ i ].value );
        }
    }
}
