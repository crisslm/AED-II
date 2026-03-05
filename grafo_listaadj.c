#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Peso;
#define MAX 100;

//Vertice destino, peso, ponteiro p/prox aresta
typedef struct str_aresta{
    int vdest;
    Peso peso;
    struct str_aresta *prox;  
}Aresta;

typedef struct{
    Aresta **listaAdj;
    int numVertices;
}grafo_adj;

bool inicializa_grafo(grafo_adj *g, int nv){
    if(nv <= 0){
        printf("Erro: Numero de vertices menor ou igual a zero.");
        return false;
    }
    g->numVertices = nv;
    if(!g->listaAdj = (Aresta**)calloc(nv, sizeof(Aresta*))){
        printf("Erro: problema ao alocar memória");
        return false;
    }
    return true;
}

bool adicionar_vertice(grafo_adj *g, int from, int to){

}



int main(){
     

    return 0;
}