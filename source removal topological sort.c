#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to represent an adjacency list (modified for simplicity)
int graph[MAX_VERTICES][MAX_VERTICES];

// Function to add an edge to the graph (modified for simplicity)
void addEdge(int src, int dest) {
  graph[src][dest] = 1;
}

// Function to perform topological sort using source removal
void topologicalSort(int V) {
  int in_degree[MAX_VERTICES] = {0};
  int sorted[MAX_VERTICES];
  int index = 0;

  // Calculate in-degree of each vertex
  for (int v = 0; v < V; ++v) {
    for (int w = 0; w < V; ++w) {
      if (graph[v][w] == 1) {
        in_degree[w]++;
      }
    }
  }

  // Find sources (nodes with in-degree 0)
  for (int i = 0; i < V; i++) {
    if (in_degree[i] == 0) {
      sorted[index++] = i;
    }
  }

  // Process sources and update in-degree of neighbors
  for (int i = 0; i < index; i++) {
    int v = sorted[i];
    for (int w = 0; w < V; ++w) {
      if (graph[v][w] == 1) {
        in_degree[w]--;
        if (in_degree[w] == 0) {
          sorted[index++] = w;
        }
      }
    }
  }

  // Check for cycle
  if (index != V) {
    printf("Graph contains a cycle. Topological sort not possible.\n");
  } else {
    printf("Topological Sort of the Graph:\n");
    for (int i = 0; i < index; i++) {
      printf("%d ", sorted[i]);
    }
    printf("\n");
  }
}

int main() {
    int i,a,b,V;
    printf("enter number of vertices:");
    scanf("%d",&V);
    for(i=0;i<V;i++){
        printf("edge %d:\n",i+1);
        scanf("%d",&a);
        scanf("%d",&b);
        addEdge(a,b);
    }

  topologicalSort(V);

  return 0;
}
