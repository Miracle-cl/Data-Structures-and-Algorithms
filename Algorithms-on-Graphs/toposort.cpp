#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

class TopologicalSort
{
    int n_size;
    int cc = 1;
    vector<vector<int> > adj;
    vector<int> used;
    vector<int> post_order;

public:
    explicit TopologicalSort(int nn): n_size(nn), adj(nn, vector<int>()), used(nn, 0), post_order(nn, 0) {}

    bool static cmp(pair <int, int> p, pair <int, int> q) {
        return p.second > q.second;
    }

    void read_adj(int m) {
        for (size_t i = 0; i < m; i++) {
          int x, y;
          std::cin >> x >> y;
          adj[x - 1].push_back(y - 1);
        }
    }

    void postvisit(int v) {
        post_order[v] = cc;
        ++cc;
    }

    void explore(int v) {
        used[v] = 1;
        for (size_t w : adj[v]) {
            if (!used[w]) {
                explore(w);
            }
        }
        postvisit(v);
    }

    void dfs() {
        //write your code here
        for (int i = 0; i < adj.size(); ++i) {
            if (!used[i])
                explore(i);
        }
    }

    vector<int> toposort() {
        //write your code here
        dfs();

        vector< pair<int, int> > rs;
        for (int i = 0; i < post_order.size(); ++i)
            rs.push_back(pair <int, int> (i+1, post_order[i]));
        sort(rs.begin(), rs.end(), cmp);

        vector<int> result;
        for (auto x: rs)
            result.push_back(x.first);

        return result;
    }
};

int main() {
    size_t n, m;
    std::cin >> n >> m;
    // vector<vector<int> > adj(n, vector<int>());
    // for (size_t i = 0; i < m; i++) {
    //   int x, y;
    //   std::cin >> x >> y;
    //   adj[x - 1].push_back(y - 1);
    // }
    // vector<int> order = toposort(adj);
    TopologicalSort ts(n);
    ts.read_adj(m);
    // ts.ff();
    vector<int> rr = ts.toposort();
    for (size_t i = 0; i < rr.size(); i++) {
        std::cout << rr[i] << " ";
    }
}
