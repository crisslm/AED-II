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
     printf("   ");
    for(int i = 0; i < g->numVertices; i++){
        if(i < 9){
            printf(" | %d",i+1);
        } else{
            printf("| %d",i+1);
        }
    }
    printf("\n");
    for(int i = 0; i < g->numVertices; i++){
        if(i < 9){
            printf("%3d|", i+1);
        } else{
            printf("%3d|", i+1);
        }
        
        for(int j = 0; j < g->numVertices; j++){
            printf("%3d ", g->matrixAdj[i][j]);
        }
        printf("\n");
    }   
    printf("\n"); 
}

void addEdge(grafo *g, int fromA, int toB, Weight peso){
    if(g->matrixAdj[fromA-1][toB-1] != 0) return;
    g->matrixAdj[fromA-1][toB-1] = peso;
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
        if(j + 1 < 10){
            printf("Vertex %d:  %d DEGREES | IN: %d | OUT: %d\n", j+1, degree, countIn, countOut);
        } else{
            printf("Vertex %d: %d DEGREES | IN: %d | OUT: %d\n", j+1, degree, countIn, countOut);
        }
        countIn = 0;
        countOut = 0;
    }
    return;
}

void adjacentVertices(grafo *g, int vertex){
    printf("Adjacent Vertices:\n");
    for(int i=0; i < g->numVertices; i++){
        if(g->matrixAdj[vertex-1][i] != 0){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");
}

int obterNrArestas(grafo *g){
    return g->numVertices;
}

bool existeAresta(grafo *g, int v1, int v2){
    if(g->matrixAdj[v1][v2] != 0) return true;
    return false;
}


int main(){
    //==============================================================================
    //A MAIN SO ACESSA O GRAFO PELAS FUNÇÕES, MAS NÃO CONHECE AS ESTRUTURA DO GRAFO.
    //==============================================================================
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
    Weight peso;
    do{
        printf("---------------------\n");
        printf("\n[1]add Edge\n[2]remove Edge\n[3]vertex degrees\n[4]show all vertices degree\n[5]Adjacents Vertices\n[0]Exit\nEnter: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("----------\n");
                printf("from: ");
                scanf("%d",&from);
                printf("to: ");
                scanf("%d",&to);
                printf("Weight: ");
                scanf("%d", &peso);
                addEdge(&g, from, to, peso);
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

            case 5:
                printf("Vertex: ");
                scanf("%d",&vertex);
                adjacentVertices(&g, vertex);
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