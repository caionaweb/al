#include <stdio.h>

int main(){
char sequenciaNumeros[50];
scanf ("%[^\n]%*c", sequenciaNumeros);
int i;
for(i=0;i<10;i++){

    printf("Palavra %c\n",sequenciaNumeros[i]);
}
return 0;
}
