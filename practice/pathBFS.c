#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Define a structure to represent a cell in the matrix
struct Cell {
    int row;
    int col;
};

// Function to check if a cell is valid and not visited
int isSafe(int row, int col, int visited[ROWS][COLS], int grid[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && !visited[row][col] && grid[row][col] == 1);
}

// Function to find a path between two cells using BFS
int hasPathBFS(int grid[ROWS][COLS], struct Cell src, struct Cell dest, struct Cell parent[ROWS][COLS]) {
    int visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    // Create a queue for BFS
    struct Cell queue[ROWS * COLS];
    int front = 0, rear = 0;

    queue[rear++] = src;
    visited[src.row][src.col] = 1;

    while (front < rear) {
        struct Cell current = queue[front++];

        if (current.row == dest.row && current.col == dest.col) {
            // Reconstruct and print the path
            struct Cell path[ROWS * COLS];
            int pathLength = 0;
            struct Cell node = dest;
            while (node.row != src.row || node.col != src.col) {
                path[pathLength++] = node;
                node = parent[node.row][node.col];
            }

            printf("Path exists. Path from source to destination:\n");
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("(%d, %d) -> ", path[i].row, path[i].col);
            }
            printf("(%d, %d)\n", dest.row, dest.col);

            return 1; // Path found
        }

        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (isSafe(newRow, newCol, visited, grid)) {
                struct Cell neighbor = {newRow, newCol};
                queue[rear++] = neighbor;
                visited[newRow][newCol] = 1;
                parent[newRow][newCol] = current; // Update the parent
            }
        }
    }

    return 0; // Path not found
}

int main() {
    int grid[ROWS][COLS] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    struct Cell src = {0, 0};
    struct Cell dest = {4, 4};
    struct Cell parent[ROWS][COLS]; // To store the parent of each cell

    if (hasPathBFS(grid, src, dest, parent)) {
        // Path printing is done within hasPathBFS function.
    } else {
        printf("No path exists.\n");
    }

    return 0;
}