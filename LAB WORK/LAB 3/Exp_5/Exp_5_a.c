//Program	to	generate	a	graph	given	in	Simple	Interaction	Format(SIF).	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINE 256

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    char* labels[MAX_NODES];  // Node labels
    Node* adjLists[MAX_NODES];
} Graph;

// Create a new adjacency node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    for (int i = 0; i < MAX_NODES; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Get index of a node label; add if not exist
int getVertexIndex(Graph* graph, char* label) {
    for (int i = 0; i < graph->numVertices; i++)
        if (strcmp(graph->labels[i], label) == 0)
            return i;

    // Add new vertex
    graph->labels[graph->numVertices] = strdup(label);
    graph->numVertices++;
    return graph->numVertices - 1;
}

// Add edge to the graph
void addEdge(Graph* graph, char* srcLabel, char* destLabel) {
    int src = getVertexIndex(graph, srcLabel);
    int dest = getVertexIndex(graph, destLabel);

    // Add edge src -> dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge dest -> src (if undirected)
    Node* newNode2 = createNode(src);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}

// Print graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s: ", graph->labels[i]);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%s -> ", graph->labels[temp->vertex]);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    char filename[MAX_LINE];
    printf("Enter SIF file name: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    Graph* graph = createGraph();
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file)) {
        char src[50], rel[50], dest[50];

        if (sscanf(line, "%s %s %s", src, rel, dest) == 3) {
            addEdge(graph, src, dest);
        }
    }

    fclose(file);

    printf("\nGraph adjacency list:\n");
    printGraph(graph);

    return 0;
}
