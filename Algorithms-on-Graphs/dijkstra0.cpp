#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

// ===== time limit exceeded (Time used: 3.98/2.00, memory used: 35287040/536870912.) =====

int extract_min(const vector<int> &dist, const vector<int> &visited) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < dist.size(); ++i) {
        if (!visited[i] && min > dist[i]) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int allvisited(const vector<int> &visited) {
    for (int x : visited) {
        if (!x)
            return 0;
    }
    return 1;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    //write your code her
    vector<int> dist(adj.size(), INT_MAX);
    vector<int> visited(adj.size(), 0);
    dist[s] = 0;

    while (!allvisited(visited)) {
        int u = extract_min(dist, visited);
        visited[u] = 1;
        if (u == t) {
            break;
        }
        else {
            for (int j = 0; j < adj[u].size(); ++j) {
                int v = adj[u][j];
                int alt = dist[u] + cost[u][j];
                if (alt < dist[v])
                    dist[v] = alt;
            }
        }
    }
    return dist[t] == INT_MAX ? -1 : dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
