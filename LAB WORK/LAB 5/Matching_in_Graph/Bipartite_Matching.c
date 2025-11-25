#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];    // adjacency matrix
int matchR[MAX];        // match for vertices on right side
bool seen[MAX];         // visited array for DFS

// DFS-based function to find if a matching for u is possible
bool bpm(int u, int nRight) {
    for (int v = 0; v < nRight; v++) {
        if (graph[u][v] && !seen[v]) {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(matchR[v], nRight)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Function to compute maximum bipartite matching
int maxBPM(int nLeft, int nRight) {
    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < nLeft; u++) {
        memset(seen, 0, sizeof(seen));
        if (bpm(u, nRight))
            result++;
    }
    return result;
}

int main() {
    int nLeft, nRight, edges;

    printf("Enter number of vertices on left side: ");
    scanf("%d", &nLeft);
    printf("Enter number of vertices on right side: ");
    scanf("%d", &nRight);

    memset(graph, 0, sizeof(graph));

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in format (u v) where u in left set [0-%d], v in right set [0-%d]:\n", nLeft-1, nRight-1);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    int maxMatch = maxBPM(nLeft, nRight);
    printf("\nMaximum number of matching in bipartite graph: %d\n", maxMatch);

    printf("Matched pairs (Right vertex -> Left vertex):\n");
    for (int v = 0; v < nRight; v++) {
        if (matchR[v] != -1)
            printf("%d -> %d\n", v, matchR[v]);
    }

    return 0;
}
