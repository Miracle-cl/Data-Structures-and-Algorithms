#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, vector<int> &visited, int v) {
    visited[v] = 1;
    for (auto w : adj[v]) {
        if (!visited[w])
            explore(adj, visited, w);
    }
}

int number_of_components(vector<vector<int> > &adj, int n) {
    int cc = 0;
    //write your code here
    vector<int> visited(adj.size(), 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            explore(adj, visited, i);
            cc++;
        }
    }
    return cc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj, n);
}
