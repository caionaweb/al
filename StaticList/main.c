#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"

int main() {
    set_configs(); // configura��es gerais

    printf( "Testando fun��es em <<staticList.h>>\n" );
    printf( "-----------------------------------------------------------------\n\n" );

    printf( "Criando lista est�tica de MAX_LENGHT posi��es...\n" );
    StaticList list = static_list_build();

    printf( "Preenchendo lista est�tica de MAX_LENGHT posi��es...\n" );
    int i;
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave num�rica do slot %d: \n", i + 1 );
        scanf( "%d", &list->slots[ i ].numericKey );
        fflush( stdin );
        printf( "Valor da chave do slot %d: \n", i + 1 );
        gets( list->slots[ i ].value );
        fflush( stdin );
    }

    printf( "\n\nImprimindo lista criada...\n" );
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave num�rica de %d: %d \n", i + 1, list->slots[ i ].numericKey );
        printf( "valor associado a chave num�rica de numero %d: %s \n", i + 1, list->slots[ i ].value );
    }

    printf( "\n\nEsvaziando a lista...\n" );
    static_list_dump( list );

    printf( "Reimprimindo lista esvaziada...\n" );
    for ( i = 0; i < MAX_LENGTH; i++) {
        printf( "Chave num�rica de %d: %d \n", i + 1, list->slots[ i ].numericKey );
        printf( "valor associado a chave num�rica de numero %d: %s \n", i + 1, list->slots[ i ].value );
    }

    printf("\n\n<<FIM TESTE>>\n\n");
    return 0;
}
