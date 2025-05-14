#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int INF = 1000000000; // A large number as infinity

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start, int dist[MAX_VERTICES], int prev[MAX_VERTICES]) {
    bool visited[MAX_VERTICES];

    for (int i = 0; i < num_vertices; ++i) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < num_vertices - 1; ++count) {
        int u = -1;
        int min_dist = INF;

        for (int i = 0; i < num_vertices; ++i) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < num_vertices; ++v) {
            if (!visited[v] && graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void print_path(int prev[MAX_VERTICES], int target) {
    if (prev[target] != -1)
        print_path(prev, prev[target]);
    cout << target << " ";
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int num_vertices = 5;

    graph[0][1] = 10;
    graph[0][4] = 5;
    graph[1][2] = 1;
    graph[1][4] = 2;
    graph[2][3] = 4;
    graph[3][0] = 7;
    graph[3][2] = 6;
    graph[4][1] = 3;
    graph[4][2] = 9;
    graph[4][3] = 2;

    int dist[MAX_VERTICES];
    int prev[MAX_VERTICES];
    int start = 0;

    dijkstra(graph, num_vertices, start, dist, prev);

    for (int i = 0; i < num_vertices; ++i) {
        cout << "Distance from " << start << " to " << i << " = " << dist[i] << ", Path: ";
        print_path(prev, i);
        cout << "\n";
    }

    return 0;
}

