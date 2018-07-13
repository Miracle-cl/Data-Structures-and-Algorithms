#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

// n(logn)^2

// using std::vector;
// using std::string;
// using std::pair;
// using std::min;
using namespace std;

struct Point {
    int x;
    int y;
};

double distance(pair <int, int> p, pair <int, int> q) {
    return pow((p.first - q.first), 2) + pow((p.second - q.second), 2);
}

bool cmpx(pair <int, int> p, pair <int, int> q) {
    return p.first < q.first;
}

bool cmpy(pair <int, int> p, pair <int, int> q) {
    return p.second < q.second;
}

double bruteforce(vector < pair<int, int> > &vp, int l, int r) {
    double min_d = FLT_MAX;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            if (distance(vp[i], vp[j]) < min_d)
                min_d = distance(vp[i], vp[j]);
        }
    }
    return min_d;
}


double closest_util(vector < pair<int, int> > &vp, int l, int r) {
    if (r - l <= 2) return bruteforce(vp, l, r);
    int mid = (l + r) / 2;
    pair<int, int> midP = vp[mid];

    double dl = closest_util(vp, l, mid);
    double dr = closest_util(vp, mid+1, r);

    double min_d = min(dl, dr);

    // point vector : -d + mid < x < d + mid
    vector< pair<int, int> > strip;
    for (int i = 0; i <= r; ++i) {
        if (abs(vp[i].first - midP.first) < min_d) {
            strip.push_back(vp[i]);
        }
    }

    // find the minumum value in strip
    sort(strip.begin(), strip.end(), cmpy);
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; (j < strip.size()) && ((strip[j].second - strip[i].second) < min_d); ++j) {
            if (distance(strip[i], strip[j]) < min_d)
                min_d = distance(strip[i], strip[j]);
        }
    }

    return min_d;
}


double minimal_distance(vector<int> x, vector<int> y, int n) {
    //write your code here
    vector < pair<int, int> > vp;
    for (int i = 0; i < n; ++i) {
        vp.push_back(pair <int, int> (x[i], y[i]));
    }
    sort(vp.begin(), vp.end(), cmpx);
    double min_d = closest_util(vp, 0, n-1);
    return sqrt(min_d);
}

int main() {
    size_t n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << fixed;
    cout << setprecision(9) << minimal_distance(x, y, n) << "\n";
}
