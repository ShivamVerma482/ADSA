//Single	source	shortest	path	(given	a	source)	using	Dijkstra	algorithm.	


#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Print shortest distances
void printSolution(int dist[], int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];     // Distance from source
    int visited[MAX];  // Visited vertices

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n);
}

int main() {
    int n, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}
