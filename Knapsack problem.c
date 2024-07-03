#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to implement the knapsack algorithm
void knapsack(int n, int m, int w[], int p[], int v[n+1][m+1]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (w[i - 1] > j) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]);
            }
        }
    }
}

// Function to determine which objects are selected
void objectSelected(int v[][101], int w[], int n, int m) {
    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i - 1] = 1;
            j = j - w[i - 1];
        }
        i--;
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("Object %d is selected\n", i + 1);
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the capacity of the bag: ");
    scanf("%d", &m);
    int w[n], p[n];
    printf("Enter the weight and profit of each object:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight %d: ", i + 1);
        scanf("%d", &w[i]);
        printf("Profit %d: ", i + 1);
        scanf("%d", &p[i]);
        printf("\n");
    }

    // Create a 2D array with dimensions (n+1) x (m+1)
    int v[n + 1][m + 1];

    // Calculate the knapsack values
    knapsack(n, m, w, p, v);

    // Output the selected objects
    objectSelected(v, w, n, m);

    return 0;
}
