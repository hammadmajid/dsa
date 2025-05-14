#include <iostream>
using namespace std;

const int MAX = 100;

struct Edge {
  int u, v, weight;
};

int parent[MAX];

int find(int x) {
  while (x != parent[x])
    x = parent[x];
  return x;
}

void union_set(int a, int b) {
  int ra = find(a);
  int rb = find(b);
  if (ra != rb)
    parent[ra] = rb;
}

void sort_edges(Edge edges[], int n) {
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (edges[j].weight > edges[j + 1].weight) {
        Edge temp = edges[j];
        edges[j] = edges[j + 1];
        edges[j + 1] = temp;
      }
}

int main() {
  int V, E;
  Edge edges[MAX], result[MAX];

  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  for (int i = 0; i < E; ++i) {
    cout << "Enter edge (u v weight): ";
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }

  for (int i = 0; i < V; ++i)
    parent[i] = i;

  sort_edges(edges, E);

  int total = 0;
  int count = 0;
  for (int i = 0; i < E && count < V - 1; ++i) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].weight;
    if (find(u) != find(v)) {
      union_set(u, v);
      result[count++] = edges[i];
      total += w;
    }
  }

  cout << "Minimum Spanning Tree:\n";
  for (int i = 0; i < count; ++i)
    cout << result[i].u << " - " << result[i].v << " : " << result[i].weight
         << "\n";

  cout << "Total Weight: " << total << "\n";

  return 0;
}
