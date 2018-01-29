#include <stdio.h>
#define QTD 10

typedef struct filaC FilaC;

struct filaC
{
    int dados[QTD];
    int inicio;
    int fim;

};


int main()
{

FilaC minhaFilaC;

minhaFilaC.dados[0] = 1;

printf("Valor: %d\n", minhaFilaC.dados[0]);

return 0;


}


