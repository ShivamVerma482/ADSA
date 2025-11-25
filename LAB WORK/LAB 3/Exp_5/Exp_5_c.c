//	All	pair	shortest	path	using	Floyd	Warshall	algorithm.

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000   // Representing "infinity"

// Function to print the distance matrix
void printSolution(int dist[][MAX], int n) {
    printf("All-Pair Shortest Distances:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(int graph[][MAX], int n) {
    int dist[MAX][MAX];

    // Initialize distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Main algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, n);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, n);

    return 0;
}
