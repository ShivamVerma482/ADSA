//program	to	find	minimum	spanning	tree	using	Prim's	algorithm	from	a	
//graph	given	in	SIF	format.	


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

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

// Find vertex with minimum key value not in MST
int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < numVertices; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

// Print MST
void printMST(int parent[], int graph[MAX][MAX]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%s - %s \t%d\n", labels[parent[i]], labels[i], graph[i][parent[i]]);
}

// Prim’s algorithm
void primMST(int graph[MAX][MAX]) {
    int parent[MAX]; // Store MST
    int key[MAX];    // Key values
    int mstSet[MAX]; // Included vertices

    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;  // Start from vertex 0
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < numVertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
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

    int graph[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char src[50], rel[50], dest[50];
        int weight;
        // Assume format: NodeA Relation NodeB Weight
        if (sscanf(line, "%s %s %s %d", src, rel, dest, &weight) == 4) {
            int u = getVertexIndex(src);
            int v = getVertexIndex(dest);
            graph[u][v] = weight;
            graph[v][u] = weight; // Undirected
        }
    }

    fclose(file);

    printf("\nMinimum Spanning Tree (Prim’s Algorithm):\n");
    primMST(graph);

    return 0;
}
