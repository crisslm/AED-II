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
        printf("|%d",i+1);
    }
    printf("\n");
    for(int i = 0; i < g->numVertices; i++){
        printf("%d|", i+1);
        for(int j = 0; j < g->numVertices; j++){
            printf("%d ", g->matrixAdj[i][j]);
        }
        printf("\n");
    }   
    printf("\n"); 
}

void addEdge(grafo *g, int fromA, int toB){
    if(g->matrixAdj[fromA-1][toB-1] != 0) return;
    g->matrixAdj[fromA-1][toB-1] = 1;
    return;
}

void removeEdge(grafo *g, int fromA, int toB){
    g->matrixAdj[fromA-1][toB-1] = 0;
}

void vertexDegrees(grafo *g, int vertex){
    int countIn = 0;
    int countOut = 0;
    for(int i=0;i<g->numVertices;i++){
        //count out
        if(g->matrixAdj[vertex-1][i] != 0) countOut++;
        //count In
        if(g->matrixAdj[i][vertex-1] != 0) countIn++;
    }
    int degree = countIn + countOut;
    printf("-----------------\n");
    printf("\nVertex %d STATUS:\nDegree: %d\nIn: %d\nOut: %d\n",vertex, degree, countIn, countOut);
    printf("-----------------\n");
}

void allVerticesDegree(grafo *g){
     printf("--------------------\n");
    printf("\nAll vertices degrees:\n");
    int countIn = 0;
    int countOut = 0;
    for(int j=0;j<g->numVertices;j++){
        for(int i=0;i<g->numVertices;i++){
            //count out
            if(g->matrixAdj[j][i] != 0) countOut++;
            //count In
            if(g->matrixAdj[i][j] != 0) countIn++;
        }
        int degree = countIn + countOut;
        printf("Vertex %d: %d degrees\n", j+1, degree);
        countIn = 0;
        countOut = 0;
    }
    printf("--------------------\n");
    return;
}

int main(){
    grafo g;
    int vertices;
    printf("How many vertices?(1-100): ");
    scanf("%d",&vertices);
    printf("\n");
    initializeGrafo(&g, vertices); //Define the number of vertices here.
    printGrafo(&g);

    int keep = 99;
    int opt;
    int from , to, vertex;
    do{
        printf("---------------------\n");
        printf("\n[1]add Edge\n[2]remove Edge\n[3]vertex degrees\n[4]show all vertices degree\n[0]Exit\nEnter: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("----------\n");
                printf("from: ");
                scanf("%d",&from);
                printf("to: ");
                scanf("%d",&to);
                addEdge(&g, from, to);
                printf("\n");
                printGrafo(&g);
            break;

            case 2:
                printf("----------\n");
                printf("from: ");
                scanf("%d",&from);
                printf("to: ");
                scanf("%d",&to);
                removeEdge(&g, from, to);
                printGrafo(&g);
                printf("----------\n");
            break;

            case 3:
                printf("Vertex: ");
                scanf("%d",&vertex);
                vertexDegrees(&g, vertex);
            break;

            case 4:
                allVerticesDegree(&g);
            
            break;

            case 0:
                keep = 0;
            break;

            default: 
                printf("Wrong Input.\n");
            break;
        }
    }while(keep != 0);

    return 0;
}