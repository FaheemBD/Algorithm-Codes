#include <stdio.h>
#include <stdbool.h>

#define V 4

void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

bool isSafe(int graph[V][V], int color[]) {
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            if (graph[i][j] && color[j] == color[i]) {
                return false;
            }
        }
    }
    return true;
}

bool graphColorUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        if (isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }

    bool res = false;
    for (int c = 1; c <= m; c++) {
        color[v] = c;
        res = graphColorUtil(graph, m, color, v+1) || res;
        color[v] = 0;
    }

    return res;
}

bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graphColorUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    return true;
}

int main() {
    int graph[V][V] = { {0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0} };
    int m = 3;

    graphColoring(graph, m);

    return 0;
}

