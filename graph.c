#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Giới hạn số lượng đỉnh tối đa

// Cấu trúc đồ thị dưới dạng ma trận kề
typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

// Khởi tạo đồ thị
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Thêm cạnh vào đồ thị
void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // Nếu đồ thị là vô hướng
}

// Hiển thị đồ thị dưới dạng ma trận kề
void displayGraph(Graph* g) {
    printf("\nMa tran ke cua do thi:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// BFS - Breadth-First Search
void BFS(Graph* g, int start) {
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("\nThu tu cac dinh duoc duyet theo BFS: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

// DFS - Depth-First Search
void DFSUtil(Graph* g, int start, bool visited[]) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[start][i] && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int start) {
    bool visited[MAX] = {false};
    printf("\nThu tu cac dinh duoc duyet theo DFS: ");
    DFSUtil(g, start, visited);
}

int main() {
    int vertices, edges, u, v, start;
    Graph g;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    displayGraph(&g);

    printf("\nNhap dinh bat dau duyet: ");
    scanf("%d", &start);

    BFS(&g, start);
    DFS(&g, start);

    return 0;
}
