#include <stdio.h>
#include <stdlib.h>

typedef struct aluno *Aluno;
typedef struct lista *Lista;

struct aluno {
    int idade;
    char nome[ 250 ];
    int codigo;
};


/*
    Uma lista estática possui um vector para segurar os dados
    e um campo inteiro para guardar o comprimento da lista
*/
struct lista {
    struct aluno alunos[ 3 ];
    int quantidade;
};



int main() {

    Lista lista_alunos = ( Lista )malloc( sizeof( struct lista ) );

    int i;
    for ( i = 0; i < 3; i++ ) {
        printf( "entre com a IDADE do aluno %d: ", i + 1 );
        scanf( "%d", &lista_alunos->alunos[ i ].idade );
        fflush( stdin );

        printf( "entre com o NOME do aluno %d: ", i + 1 );
        gets( &lista_alunos->alunos[ i ].nome );
        fflush( stdin );

        printf( "entre com CODIGO do aluno %d: ", i + 1 );
        scanf( "%d", &lista_alunos->alunos[ i ].codigo );
        fflush( stdin );
    }

    for ( i = 0; i < 3; i++ ) {
        printf( "idade do aluno %d: %d\n", i + 1, lista_alunos->alunos[ i ].idade );
        printf( "nome do aluno %d: %s\n", i + 1, lista_alunos->alunos[ i ].nome );
        printf( "codigo do aluno %d: %d\n", i + 1, lista_alunos->alunos[ i ].codigo );
    }

    return 0;
}
