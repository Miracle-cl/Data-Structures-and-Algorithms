#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &rec_stack) {
    visited[x] = 1;
    rec_stack[x] = 1;
    for (int j = 0; j < adj[x].size(); ++j) {
        if (!visited[adj[x][j]] && dfs(adj, adj[x][j], visited, rec_stack))
            return 1;
        else if (rec_stack[adj[x][j]])
            return 1;
    }
    rec_stack[x] = 0;
    return 0;
}

int acyclic(vector<vector<int> > &adj) {
    //write your code here
    vector<int> visited(adj.size(), 0);
    vector<int> rec_stack(adj.size(), 0);
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i])
            if (dfs(adj, i, visited, rec_stack))
                return 1;
    }
    return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
