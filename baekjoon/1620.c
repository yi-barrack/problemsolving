#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    int name;
    int label;
} Vertex;

typedef struct Edge{
    int end1;
    int end2;
    int label;
} Edge;

typedef struct Graph{
    Vertex vertices[1000];
    Edge edges[10000];
    int edgeinfo[10000][01000];
} Graph;

void init_graph(Graph *graph, int n, int m){
    for (int i = 0; i < n;i++){
        graph->vertices[i].name = i + 1;
    }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                graph->edgeinfo[i][j] = -1;
        }
}

void DFS(Graph *graph, int v, int n, int m);
void rDFS(Graph *graph, int v, int m);

int main()
{
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    for (int i = 0; i < m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph->edges[i].end1 = a;
        graph->edges[i].end2 = b;
        graph->edgeinfo[a][b] = 1;
        graph->edgeinfo[b][a] = 1;
    }

    init_graph(graph,n ,m);
    DFS(graph, v, n, m);


    free(graph);
    return 0;
}

void DFS(Graph *graph, int v, int n, int m){
    for (int i = 0; i < n;i++)
        graph->vertices[i - 1].label = 0;// fresh

    for (int i = 0; i < m;i++)
        graph->edges[i].label = 0;// fresh
    
    rDFS(graph, v, m);
}

void rDFS(Graph *graph, int v, int m){
    graph->vertices[v-1].label = 1;// visited
    printf("%d ", v);
    for (int i = 0; i < m;i++){
        if (graph->edges[graph->edgeinfo[v-1][i]].label == 0){
            graph->edges[graph->edgeinfo[v-1][i]].label = 1;
            int opposite = graph->edges[graph->edgeinfo[v-1][i]].end1 == v ? graph->edges[graph->edgeinfo[v-1][i]].end2 : graph->edges[graph->edgeinfo[v-1][i]].end1;
            rDFS(graph, opposite, m);
        }
        else
            graph->edges[graph->edgeinfo[v-1][i]].label = 2;// back
    }
}