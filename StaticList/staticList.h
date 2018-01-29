#include "configs.h"
#include "node.h"

#define MAX_LENGTH 3
#define U_TYPE Node // foi o mais perto que cheguei de "tipo parametrizados" em C rsrs

typedef struct static_list *StaticList;

struct static_list {
    U_TYPE slots[ MAX_LENGTH ];
    int lenght;
};

// cria lista estática com MAX_LENGHT de comprimento
StaticList static_list_build( ); // done

// destroi a lista estática
void static_list_destruct( StaticList list ); // done

// esvazia a lista estática
void static_list_dump(  StaticList list ); // done

// inseri um item no final da lista
int static_list_insert_end( StaticList list, U_TYPE item ); // done

// inseri um item no inicio da lista
int static_list_insert_begin( StaticList list, U_TYPE item ); // done

int static_list_insert_ordered_item( StaticList list, U_TYPE item );

// remove o último item da lista
int static_list_remove_item_end( StaticList list ); // done

// remove o primeiro item da lista
int static_list_remove_item_begin( StaticList list ); // done

// remove um item baseado numa chave numérica
int static_list_remove_item( StaticList list, int numericKey ); // done

// retorna comprimento da lista
int static_list_get_lenght( StaticList list ); // done

// retorna true se a lista estiver vazia
int static_list_is_empty( StaticList list ); // done

// retorna true se a lista estiver cheia
int static_list_is_full( StaticList list ); // done

// imprime uma lista estática
void static_list_print( StaticList list ); // done
