#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define max 100
typedef int Weight;

typedef struct{
    Weight matrixAdj[max][max];
    int numVertices;
}grafo;

void initializeGrafo(grafo *g, int numVertices){
    g->numVertices = numVertices;
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            g->matrixAdj[i][j] = 0;
        } 
    }
    return;
}

void printGrafo(grafo *g){
     printf(" ");
    for(int i = 0; i < g->numVertices; i++){
        printf("|%d",i);
    }
    printf("\n");
    for(int i = 0; i < g->numVertices; i++){
        printf("%d|", i);
        for(int j = 0; j < g->numVertices; j++){
            printf("%d ", g->matrixAdj[i][j]);
        }
        printf("\n");
    }   
    printf("\n"); 
}

void addEdge(grafo *g, int fromA, int toB){
    if(g->matrixAdj[fromA][toB] != 0) return;
    g->matrixAdj[fromA][toB] = 1;
    return;
}

void removeEdge(grafo *g, int fromA, int toB){
    if(g->matrixAdj[fromA][toB] == 0) return;
    g->matrixAdj[fromA][toB] = 0;
}

int verticeDegree(grafo *g, int vertice){
    int countIn = 0;
    int countOut = 0;
    for(int i=0;i<g->numVertices;i++){
        //count out
        if(g->matrixAdj[vertice][i] != 0) countOut++;
        //count In
        if(g->matrixAdj[i][vertice] != 0) countIn++;
    }
    int degree = countIn + countOut;
    return degree;
}

int main(){
    grafo g;
    initializeGrafo(&g, 6); //Define the number of vertices here.
    printGrafo(&g);

    int keep = 99;
    int opt;
    int from , to, vertice, vertice_degree;
    do{
        printf("\n[1]add Edge\n[2]remove Edge\n[3]vertice degree\n[0]Sair\nEnter: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("from: ");
                scanf("%d",&from);
                printf("to: ");
                scanf("%d",&to);
                addEdge(&g, from, to);
                printGrafo(&g);
            break;

            case 2:
                printf("from: ");
                scanf("%d",&from);
                printf("to: ");
                scanf("%d",&to);
                removeEdge(&g, from, to);
                printGrafo(&g);
            break;

            case 3:
                printf("Vertice: ");
                scanf("%d",&vertice);
                vertice_degree = verticeDegree(&g, vertice);
                printf("\nVertice %d degree is %d.\n", vertice, vertice_degree);
            break;

            case 0:
                keep = 0;
            break;

            default: 
                printf("Wrong Input.\n");
            break;
        }
    }while(keep != 0);

    printf("%d ", g.numVertices);



    return 0;
}