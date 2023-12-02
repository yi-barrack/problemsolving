#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int edgeidx;
    int opposite;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

typedef struct Vertex
{
    int name;
    int label;
    List *edge_info;
} Vertex;

typedef struct Edge
{
    int v1;
    int v2;
    int label;
} Edge;

typedef struct Graph
{
    Vertex *vertices;
    Edge *edges;
} Graph;

Node *get_node();
void init_graph(Graph *graph, int n, int m);
void init_list(List *list);
void add_node(List *list, int edgeidx, int opposite);
void add_last(List *list, int edgeidx, int opposite);
void DFS(Graph *graph, int n, int m, int v);
void rDFS(Graph *graph, int v);
void BFS(Graph *graph, int n, int m, int v);

int main()
{
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    init_graph(graph, n, m);
    DFS(graph, n, m, v);
    printf("\n");
    BFS(graph, n, m, v);

    for (int i = 0; i < n; i++)
    {
        Node *pnode = graph->vertices[i].edge_info->head;
        while (pnode != NULL)
        {
            Node *qnode = pnode;
            pnode = pnode->next;
            free(qnode);
        }
        free(graph->vertices[i].edge_info);
    }
    free(graph->vertices);
    free(graph->edges);
    free(graph);
    return 0;
}

void BFS(Graph *graph, int n, int m, int v)
{
    Vertex *vertices = graph->vertices;
    Edge *edges = graph->edges;
    for (int i = 0; i < n; i++)
        vertices[i].label = 0;

    for (int i = 0; i < m; i++)
        edges[i].label = 0;

    List *queue = (List *)malloc(sizeof(List));
    init_list(queue);
    vertices[v - 1].label = 1;
    printf("%d ", v);
    add_node(queue, -1, v);
    Node *pnode = queue->head->next;
    while (pnode != NULL)
    {
        List *list = vertices[pnode->opposite - 1].edge_info;
        Node *qnode = list->head->next;
        while (qnode != NULL)
        {
            if (edges[qnode->edgeidx].label == 0)
            {
                if (vertices[qnode->opposite - 1].label == 0)
                {
                    edges[qnode->edgeidx].label = 1;
                    vertices[qnode->opposite - 1].label = 1;
                    printf("%d ", qnode->opposite);
                    add_last(queue, -1, qnode->opposite);
                }
                else
                    edges[qnode->edgeidx].label = 2;
            }
            qnode = qnode->next;
        }
        pnode = pnode->next;
    }
    while (queue->head->next != NULL)
    {
        Node *pnode = queue->head->next;
        queue->head->next = pnode->next;
        free(pnode);
    }
    free(queue);
}

void add_last(List *list, int edgeidx, int opposite)
{
    Node *newnode = get_node();
    newnode->edgeidx = edgeidx;
    newnode->opposite = opposite;
    list->tail->next = newnode;
    list->tail = newnode;
}

void DFS(Graph *graph, int n, int m, int v)
{
    for (int i = 0; i < n; i++)
        graph->vertices[i].label = 0;

    for (int i = 0; i < m; i++)
        graph->edges[i].label = 0;

    rDFS(graph, v);
}

void rDFS(Graph *graph, int v)
{
    Vertex *vertices = graph->vertices;
    Edge *edges = graph->edges;
    List *list = vertices[v - 1].edge_info;
    Node *pnode = list->head->next;

    vertices[v - 1].label = 1; // visited
    printf("%d ", v);
    while (pnode != NULL)
    {
        if (edges[pnode->edgeidx].label == 0)
        {
            if (vertices[pnode->opposite - 1].label == 0)
            {
                edges[pnode->edgeidx].label = 1; // tree
                rDFS(graph, pnode->opposite);
            }
            else
                edges[pnode->edgeidx].label = 2; // back
        }
        pnode = pnode->next;
    }
}

Node *get_node()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->edgeidx = -1;
    newnode->next = NULL;
    newnode->opposite = -1;
    return newnode;
}

void init_graph(Graph *graph, int n, int m)
{
    graph->vertices = (Vertex *)malloc(sizeof(Vertex) * n);
    graph->edges = (Edge *)malloc(sizeof(Edge) * m);

    for (int i = 0; i < n; i++)
    {
        graph->vertices[i].name = i + 1;
        graph->vertices[i].label = 0;
        graph->vertices[i].edge_info = (List *)malloc(sizeof(List));
        init_list(graph->vertices[i].edge_info);
    }
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph->edges[i].v1 = v1;
        graph->edges[i].v2 = v2;
        add_node(graph->vertices[v1 - 1].edge_info, i, v2);
        add_node(graph->vertices[v2 - 1].edge_info, i, v1);
    }
}

void init_list(List *list)
{
    list->head = get_node();
    list->tail = list->head;
}

void add_node(List *list, int edgeidx, int opposite)
{
    Node *newnode = get_node();
    newnode->edgeidx = edgeidx;
    newnode->opposite = opposite;

    Node *pnode = list->head;
    while (1)
    {
        if (pnode->next == NULL)
        {
            pnode->next = newnode;
            list->tail = newnode;
            return;
        }
        if (pnode->next->opposite > opposite)
        {
            newnode->next = pnode->next;
            pnode->next = newnode;
            return;
        }
        pnode = pnode->next;
    }
}