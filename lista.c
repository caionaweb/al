#include <stdio.h>
#define TMAX 4

typedef struct lista{
int elemento[TMAX];
int ultimo;
}Lista;

void inicializalista(Lista *l){
l->ultimo = -1;
}

int listacheia(Lista *l){
if(l->ultimo==TMAX-1){
return 1;
}else{
return 0;
}
}

int listavazia(Lista *l){
if(l->ultimo==-1){
return 1;
}else{
return 0;
}
}

int inserirfim(Lista *l, int num){
if(listacheia(l)){
printf("Lista cheia.");
return 0;
}else{
l->elemento[l->ultimo+1]=num;
l->ultimo++;
return 1;
}
}

int modificar(Lista *l, int posicao, int valor){
if(posicao <0 || posicao > l->ultimo){
printf("Posicao Invalida\n");
return 0;
}else{
l->elemento[posicao]=valor;
return 1;
}
}

int remover(Lista *l, int posicao){
int i;
if(listavazia(l)){
printf("Lista Vazia!\n");
return 0;
}

if(posicao<0 || posicao > l->ultimo){
printf("Posicao Invalida\n");
return 0;
}

for(i=posicao;i<l->ultimo;i++){
l->elemento[i]=l->elemento[i+1];
}
l->elemento[l->ultimo]=0;
l->ultimo--;

return 1;

}


int acessar(Lista *l, int posicao){
if(posicao<0 || posicao > l->ultimo){
printf("Posicao Invalida!\n");
return 0;
}

return l->elemento[posicao];

}

int pesquisaelemento(Lista *l, int valor){
int i;
if(listavazia(l)){
printf("Lista Vazia!");
return 0;
}

for(i=0;i<=l->ultimo;i++){
if(l->elemento[i]==valor){
return i;
}

return -1;
}

}



int tamanhodalista(Lista *l){

if(listavazia(l)){
printf("Lista Vazia!\n");
return 0;
}

return l->ultimo;
}

int printlista(Lista *l){
int i;
if(listavazia(l)){
printf("Lista Vazia!\n");
return 0;
}

for(i=0;i<=l->ultimo;i++){
printf("O valor da Posicao %d e: %d",i,l->elemento[i]);
}
return 1;
}


int main(){

Lista l;
int i;
inicializalista(&l);

for(i=0;i<TMAX;i++){

inserirfim(&l,i);

}
printlista(&l);
return 0;
}