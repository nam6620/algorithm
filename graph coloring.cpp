#include <stdbool.h>
#include <stdio.h>

#define NUM_VERTICES 5

bool is_safe(int vertex, int color, int graph[NUM_VERTICES][NUM_VERTICES], int colors[NUM_VERTICES]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int graph[NUM_VERTICES][NUM_VERTICES], int num_colors, int colors[NUM_VERTICES], int vertex) {
    if (vertex == NUM_VERTICES) {
        return true;
    }

    for (int color = 1; color <= num_colors; color++) {
        if (is_safe(vertex, color, graph, colors)) {
            colors[vertex] = color;
            if (graph_coloring_util(graph, num_colors, colors, vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

bool graph_coloring(int graph[NUM_VERTICES][NUM_VERTICES], int num_colors) {
    int colors[NUM_VERTICES] = {0};

    if (!graph_coloring_util(graph, num_colors, colors, 0)) {
        printf("No solution exists.");
        return false;
    }

    printf("Solution exists with the following color assignments:\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
    return true;
}

int main() {
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int num_colors = 3; // Number of colors available

    graph_coloring(graph, num_colors);

    return 0;
}
