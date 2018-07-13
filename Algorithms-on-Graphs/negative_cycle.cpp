#include <iostream>
#include <vector>
#include <climits>

using std::vector;
using std::pair;
using std::make_pair;

//  ====== Good job! (Max time used: 0.07/2.00, max memory used: 10387456/536870912.)

int negative_cycle(vector< pair<int, int> > &adj, vector<int> &cost, int n, int m) {
    //write your code here
    // Initialize distances

    vector<int> dist(n, 0); // INT_MAX is not right for #12/19;

    // vector<int> prev(n);
    // dist[0] = 0;

    // relax all edges;  guarantees shortest distances
    // repeat n - 1  times
    for (int cc = 1; cc < n; ++cc) {
        for (int i = 0; i < m; ++i) {
            int u = adj[i].first;
            int v = adj[i].second;
            int w = cost[i];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // prev[v] = u;
            }
        }
    }

    // check for negative-weight cycles
    for (int i = 0; i < m; ++i) {
        int u = adj[i].first;
        int v = adj[i].second;
        int w = cost[i];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return 1;
        }
    }

    return 0;

}

int main() {
    int n, m;
    std::cin >> n >> m;
    // vector< pair<int, int> > adj(m);  cannot push back
    vector< pair<int, int> > adj;  // can push back
    vector<int> cost;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj.push_back(make_pair(x-1, y-1));
        cost.push_back(w);
    }
    std::cout << negative_cycle(adj, cost, n, m);
}
