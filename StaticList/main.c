#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"

int main() {
    set_configs(); // configurações gerais

    printf( "Testando funções em <<staticList.h>>\n" );
    printf( "-----------------------------------------------------------------\n\n" );

    printf( "Criando lista estática de MAX_LENGHT posições...\n" );
    StaticList list = static_list_build();

    printf( "Preenchendo lista estática de MAX_LENGHT posições...\n" );
    int i;
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave numérica do slot %d: \n", i + 1 );
        scanf( "%d", &list->slots[ i ].numericKey );
        fflush( stdin );
        printf( "Valor da chave do slot %d: \n", i + 1 );
        gets( list->slots[ i ].value );
        fflush( stdin );
    }

    printf( "\n\nImprimindo lista criada...\n" );
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave numérica de %d: %d \n", i + 1, list->slots[ i ].numericKey );
        printf( "valor associado a chave numérica de numero %d: %s \n", i + 1, list->slots[ i ].value );
    }

    printf( "\n\nEsvaziando a lista...\n" );
    static_list_dump( list );

    printf( "Reimprimindo lista esvaziada...\n" );
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave numérica de %d: %d \n", i + 1, list->slots[ i ].numericKey );
        printf( "valor associado a chave numérica de numero %d: %s \n", i + 1, list->slots[ i ].value );
    }

    printf("\n\n<<FIM TESTE>>\n\n");
    return 0;
}
