#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using std::make_pair;

// Good job! (Max time used: 0.01/2.00, max memory used: 9105408/536870912.)

typedef pair<int, int> ipair;

class Kruskal {
    int n_vertexes;
    vector<ipair> vertexes;
    vector<int> parents;
    vector<int> ranks;

public:
    explicit Kruskal(int nn): n_vertexes(nn), vertexes(nn), parents(nn), ranks(nn) {}

    void makeset_input() {
        for (size_t i = 0; i < n_vertexes; i++) {
            std::cin >> vertexes[i].first >> vertexes[i].second;
            // vertexes[i] = make_pair(vertexes[i].first, vertexes[i].first);
            parents[i] = i;
            ranks[i] = 0;
        }
    }

    int find_i(int i) {
        while (i != parents[i])
            i = parents[i];
        return i;
    }

    void union_ij(int i, int j) {
        int iid = find_i(i);
        int jid = find_i(j);
        if (iid == jid)
            return;
        if (ranks[iid] > ranks[jid])
            parents[jid] = iid;
        else {
            parents[iid] = jid;
            if (ranks[iid] == ranks[jid])
                ranks[jid]++;
        }
    }

    double compute_dist(int i, int j) {
        return sqrt(pow(vertexes[i].first - vertexes[j].first, 2) + pow(vertexes[i].second - vertexes[j].second, 2));
    }

    // bool cmp(pair<double, ipair> p, pair<double, ipair> q) {
    //     return p.first < q.first;
    // }

    double minimum_distance() {
        double result = 0.;
        //write your code here
        // edges and (s, t)
        vector<pair<double, ipair>> edges;
        for (int i = 0; i < n_vertexes - 1; ++i) {
            for (int j = i + 1; j < n_vertexes; ++j) {
                double ww = compute_dist(i, j);
                edges.push_back(make_pair(ww, make_pair(i, j)));
            }
        }
        sort(edges.begin(), edges.end());
        // for (auto x : edges) {
        //     std::cout << x.first << " " << x.second.first << x.second.second << "\n";
        // }
        for (auto x : edges) {
            if (find_i(x.second.first) != find_i(x.second.second)) {
                result += x.first;
                union_ij(x.second.first, x.second.second);
            }
        }

        return result;
    }
};


// double minimum_distance(vector<int> x, vector<int> y) {
//     double result = 0.;
//     //write your code here
//     return result;
// }

int main() {
  size_t n;
  std::cin >> n;
  // vector<int> x(n), y(n);
  // for (size_t i = 0; i < n; i++) {
  //   std::cin >> x[i] >> y[i];
  // }
  Kruskal kk(n);
  kk.makeset_input();
  // kk.minimum_distance();
  std::cout << std::setprecision(10) << kk.minimum_distance() << std::endl;
  // std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
  return 0;
}
