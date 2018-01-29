#include <stdio.h>
#define PMAX 100


typedef struct pilha{
char dados[PMAX];
int topo;
}Pilha;

int iniciafila(Pilha *p){
p->topo=0;
return 1;
}

int pilhacheia(Pilha *p){

if(p->topo==PMAX){
    return 1;
}
return 0;

}

int pilhavazia(Pilha *p){
if(p->topo==0){
    return 1;

}
return 0;
}

int push(Pilha *p, int valor){
if(pilhacheia(p)){
    printf("Pilha Cheia!");
    return 0;
}

p->dados[p->topo]=valor;
p->topo++;
return 1;
}

int pop(Pilha *p){

if(pilhavazia(p)){

    return 0;
}

char aux;
aux = p->dados[p->topo - 1];
p->dados[p->topo - 1] = NULL;
p->topo--;

return aux;

}

int printpilha(Pilha *p){
int i;

for(i=p->topo-1;i!=-1;i--){
    printf("%c",p->dados[i]);

}
return 0;
}

int flush(Pilha *p){
int i;
for(i=0;i<p->topo;i++){
    pop(p);
}
return 0;
}



int main() {

char frase[100];
int i;
Pilha *p;
iniciafila(p);
scanf("%[^\n]s", frase);

for(i=0;i<strlen(frase);i++){

        if(frase[i]==0x20){
            printpilha(p);
            flush(p);
        }
   push(p,frase[i]);
   // if(frase[i]==0x20){
   // printf("");

    // }
    //printf("%c", pop(p));
//printf("%c", frase[i]);

}

return 1;

}

