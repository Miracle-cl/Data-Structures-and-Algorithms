#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;

// ====== Good job! (Max time used: 0.21/2.00, max memory used: 43368448/536870912.) ======

// 1) Initialize distances of all vertices as infinite.
// 2) Create an empty priority_queue pq.  Every item
//    of pq is a pair (weight, vertex). Weight (or
//    distance) is used used as first item  of pair
//    as first item is by default used to compare
//    two pairs
// 3) Insert source vertex into pq and make its
//    distance as 0.
// 4) While either pq doesn't become empty
//     a) Extract minimum distance vertex from pq.
//        Let the extracted vertex be u.
//     b) Loop through all adjacent of u and do
//        following for every vertex v.
//
//            // If there is a shorter path to v
//            // through u.
//            If dist[v] > dist[u] + weight(u, v)
//
//                (i) Update distance of v, i.e., do
//                      dist[v] = dist[u] + weight(u, v)
//                (ii) Insert v into the pq (Even if v is
//                     already there)
// 5) Print distance array dist[] to print all shortest
//    paths.

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    //write your code here
    // Create an empty priority_queue pq (weight, vertex) : weight = distance
    priority_queue < pair <int, int> > pq;
    vector<int> dist(adj.size(), INT_MAX);
    //vector<int> prev(adj.size());
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int u = pq.top().second; // vertex with max distance
        pq.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            int w = cost[u][i];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                // prev[v] = u;
                pq.push(make_pair(dist[v], v));
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
