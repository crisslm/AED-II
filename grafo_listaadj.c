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
    g->listaAdj = (Aresta**)calloc(nv, sizeof(Aresta*));
    if(!g->listaAdj){
        printf("Erro: problema ao alocar memória");
        return false;
    }
    return true;
}

bool listaAdjVazia(grafo_adj *g, int v){
    if(!g) return true;
    return !g->listaAdj[v];
}

Aresta* proxListaAdj(int v, grafo_adj *g, Aresta* atual){
    if(v < 0) return NULL;
    if(!atual) return NULL;
    return atual->prox;
}

Aresta* primeiro_lista_adj(grafo_adj *g, int v){
    if(v < 0) return NULL;
    if(!g->listaAdj[v]) return NULL;
    return g->listaAdj[v];
}

bool adicionar_aresta(grafo_adj *g, int from, int to, Peso peso){
    if(!g) return false;
    Aresta* novaAresta = malloc(sizeof(Aresta));
    novaAresta->peso = peso;
    novaAresta->vdest = to;
    novaAresta->prox = NULL;
    if(g->listaAdj[from] == NULL){
        g->listaAdj[from] = novaAresta;
    }
    else{
        Aresta* atual = g->listaAdj[from];
        while(atual->prox){
            atual = atual->prox;
        }
        atual->prox = novaAresta;
    }
    return true;
}

bool existe_aresta(int v1, int v2, grafo_adj *g){
    Aresta* p = g->listaAdj[v1];
    while(p){
        if(p->vdest == v2){
            return true;
        }
        p = p->prox;
    }
    return false;
}

Aresta* busca_aresta(grafo_adj *g, int from, int to, Aresta* *ant){
    *ant = NULL;
    Aresta* p = g->listaAdj[from];
    while(p){
        if(p->vdest == to){
            return p;
        }
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

bool remover_aresta(grafo_adj *g, int from, int to){
    if(!g) return false;
    Aresta* ant;
    Aresta* atual = busca_aresta(g, from, to, &ant);
    if(!atual) return false;
    if(ant) ant->prox = atual->prox;
    else g->listaAdj[from] = atual->prox;
    free(atual);   
}

void vizualizar_grafo(grafo_adj *g){
    int i;
    for(i=0;i<g->numVertices;i++){
        Aresta* p = g->listaAdj[i];
        printf("%d -> ", i);
        while(p){
            if(p->vdest != -1){
                printf("(vdest:%d, peso:%d) -> ", p->vdest, p->peso);
            }
            p = p->prox;
        }
        printf("\n");
    }
}



int main(){
    grafo_adj g;
    inicializa_grafo(&g, 6);
    adicionar_aresta(&g, 3, 5, 15);
    adicionar_aresta(&g, 1, 5, 10);
    adicionar_aresta(&g, 3, 5, 12);
    adicionar_aresta(&g, 5, 2, 10);
    vizualizar_grafo(&g);
    printf("\n");
    remover_aresta(&g, 3, 9);
    remover_aresta(&g, 1, 5);

    vizualizar_grafo(&g);
   
    return 0;
}