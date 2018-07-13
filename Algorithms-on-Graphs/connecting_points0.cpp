#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
// using std::vector;

struct VertexEdge {
    int x1;
    int y1;
    int x2;
    int y2;
    double w;

    VertexEdge(int x1_, int y1_, int x2_, int y2_, double w_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), w(w_) {}
};

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.;
    //write your code here
    vector<VertexEdge> ve;
    for (int i = 0; i < x.size()-1; ++i) {
        for(int j = i+1; j < x.size(); ++j) {
            double ww = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            ve.push_back(VertexEdge(x[i], y[i], x[j], y[j], ww));
            // std::cout << x[i] << y[i] << x[j] << y[j] << ww << "\n";
        }
    }
    return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
