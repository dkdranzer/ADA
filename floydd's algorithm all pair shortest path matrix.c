#include<stdio.h>
#include<limits.h> // Include limits.h for INT_MAX constant

// Function to find minimum of two integers
int min(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input validation to ensure n is a positive integer
    if (n <= 0) {
        printf("Invalid number of vertices.\n");
        return 1; // Exit with error code 1
    }

    int graph[n][n];

    // Initialize graph with a large value (INT_MAX)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Set diagonal elements to 0
    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges from source to destination and their weight:\n");
    for(int i = 0; i < edges; i++) {
        int src, dest, wt;
        printf("Edge %d\n", i + 1);
        scanf("%d %d %d", &src, &dest, &wt);

        // Input validation to ensure vertices are within range
        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            printf("Invalid edge. Vertex out of range.\n");
            return 1; // Exit with error code 1
        }

        graph[src][dest] = wt;
    }

    // Floyd-Warshall Algorithm
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Update shortest path if a shorter path is found
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    // Output the shortest paths matrix
    printf("Shortest Paths Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
