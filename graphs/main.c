#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 9999

typedef struct mygraph{
    int numnodes;
    int **edges; // Double pointer = 2d array
} graph;

void destroyGraph(graph *g){
    if(g->edges == NULL)
        return;

    for(int i = 0; i < g->numnodes; i++)
    {
        if(g->edges[i] != NULL){
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
}

graph *createGraph(int num){
    graph *g = (graph *) malloc(sizeof(graph));
    if(g == NULL){
        return NULL;
    }

    g->numnodes = num;
    g->edges = calloc(sizeof(int*), g->numnodes); // Initializes all to 0
    if(g->edges == NULL){
        free(g);
        return NULL;
    }
    for(int i = 0; i < g->numnodes; i++){
        g->edges[i] = calloc(sizeof(int),g->numnodes);
        if(g->edges[i] == NULL){
            destroyGraph(g);
            return NULL;
        }
    }
    return g;
}

bool hasEdge(graph *g, int from, int to){
    if(g == NULL){
        return NULL;
    }
    if(g->edges[from][to] == 0){
        return false;
    }
    return true;
}

void printAdjMatrix(graph *g) {

  for (int i = 0; i < g->numnodes; i++) {
      for (int j = 0; j < g->numnodes; j++) {
          if(g->edges[i][j] > 0){
              printf("%d -> %d, %d\n",i, j, g->edges[i][j]);
          }
    }
    printf("\n");
  }
}

bool addEdge(graph *g, int num, int from, int to){

    if(hasEdge(g, from, to)){
        return false;
    }
    g->edges[from][to] = num;

    return true;
}

void Djikstra(graph *g, int n, int start) {
    
    int **numArr = g->edges, max = g->numnodes;
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        if (numArr[i][j] == 0)
            cost[i][j] = INFINITY; // Infinity assigned to cost where there are no edges between two nodes
        else
            cost[i][j] = numArr[i][j]; // Otherwise, assign edge length from source to destination node

    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY; // Set minimum distance to the max which is 9999

        for (i = 0; i < n; i++)
        if (distance[i] < mindistance && !visited[i]) { // Compares current distance iter with the minDistance and checks if node has been visited
            mindistance = distance[i]; // Min distance is then replaced by current distance iter
            nextnode = i; // Next node will then be the one with a valid shortest distance
        }

        visited[nextnode] = 1; // Marks shortest path outside of current node as visited
        for (i = 0; i < n; i++)
        if (!visited[i]) // Finds next unvisited node
            if (mindistance + cost[nextnode][i] < distance[i]) { // Updates shortest distance from source to all nodes out of current node by adding minDistance and cost.
            distance[i] = mindistance + cost[nextnode][i];
            pred[i] = nextnode; // Updates predecessor by assigning it current node's index.
            }
        count++;
    }

    // Printing the distance
    printf("If distance = 9999, that means no valid route to that node.\n");
    for (i = 0; i < n; i++)
        if (i != start) {
        printf("\nDistance from source to %d: %d", i, distance[i]);
        }
}

int main(){

    int numnodes = 0, numToPath;
    printf("How many nodes are there: ");
    scanf("%d", &numnodes);
    graph *g = createGraph(numnodes);

    while(true){
        int from, to, val, check;
        printf("Add nodes (Origin) -> (Destination), cost: ");
        scanf("%d %d %d", &from, &to, &val);
        addEdge(g, val, from, to);
        printf("\nDo you want to add more? 0 or 1: ");
        scanf("%d", &check);
        if(check == 0)
            break;
    }
    printf("\n");
    printAdjMatrix(g);
    do{
        printf("From what node do you want to start with? ");
        scanf("%d", &numToPath);
    }while(numToPath >= numnodes);
    Djikstra(g, numnodes, numToPath);

    return 0;
}