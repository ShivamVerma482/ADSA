//program	to	find	minimum	spanning	tree	using	Kruskal's	algorithm	from	a	
//graph	given	in	SIF	format.	


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge edges[MAX];
} Graph;

// Node labels
char* labels[MAX];
int numVertices = 0;

// Get index of a node label, add if not exist
int getVertexIndex(char* label) {
    for (int i = 0; i < numVertices; i++)
        if (strcmp(labels[i], label) == 0)
            return i;

    labels[numVertices] = strdup(label);
    numVertices++;
    return numVertices - 1;
}

// Disjoint Set (Union-Find) functions
int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void unite(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX];
    int e = 0, i = 0;

    // Sort edges by weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), cmp);

    int parent[MAX], rank[MAX];
    for (int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unite(parent, rank, x, y);
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%s - %s \t%d\n", labels[result[i].src], labels[result[i].dest], result[i].weight);
}

int main() {
    char filename[100];
    printf("Enter SIF file name: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    Graph graph;
    graph.E = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char srcLabel[50], rel[50], destLabel[50];
        int weight;

        if (sscanf(line, "%s %s %s %d", srcLabel, rel, destLabel, &weight) == 4) {
            int u = getVertexIndex(srcLabel);
            int v = getVertexIndex(destLabel);
            graph.edges[graph.E].src = u;
            graph.edges[graph.E].dest = v;
            graph.edges[graph.E].weight = weight;
            graph.E++;
        }
    }

    fclose(file);

    graph.V = numVertices;

    kruskalMST(&graph);

    return 0;
}
