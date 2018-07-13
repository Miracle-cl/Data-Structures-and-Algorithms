#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, int n, int m) {
    //write your code here
    // Initialize distances
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // relax all edges;  guarantees shortest distances
    // repeat adj.size() - 1  times
    for (int cc = 1; cc < n; ++cc) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                int v = adj[i][j];
                int w = cost[i][j];
                if (dist[i] != INT_MAX && dist[v] > dist[i] + w) {
                    dist[v] = dist[i] + w;
                }
            }
        }
    }

    // check for negative-weight cycles
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            int v = adj[i][j];
            int w = cost[i][j];
            if (dist[i] != INT_MAX && dist[v] > dist[i] + w)
                return 1;
        }
    }
    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost, n, m);
}
