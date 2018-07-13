#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

struct Pairs
{
    int value; // the value of a segment
    int loc; // the location of a segment: left, right or point - l, r, p
    Pairs(int value, int loc) : value(value), loc(loc) {}
};

bool cmp(Pairs a, Pairs b) {
    if (a.value == b.value) {
        return a.loc < b.loc;
    }
    return a.value < b.value;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    //write your code here
    vector<Pairs> arr;
    // left.loc == 0; points.loc == 1; right.loc == 2
    for (int i = 0; i < starts.size(); ++i)
        arr.push_back(Pairs(starts[i], 0));

    for (int i = 0; i < points.size(); ++i)
        arr.push_back(Pairs(points[i], 1));

    for (int i = 0; i < ends.size(); ++i)
        arr.push_back(Pairs(ends[i], 2));

    sort(arr.begin(), arr.end(), cmp);

    int coverage = 0;
    map<int, int> result;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].loc == 0) {
            coverage += 1;
        }
        if (arr[i].loc == 1) {
            result[arr[i].value] = coverage;
        }
        if (arr[i].loc == 2) {
            coverage -= 1;
        }
    }

    for (int i = 0; i < points.size(); ++i)
        cnt[i] = result[points[i]];
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    //use fast_count_segments
    //vector<int> cnt = naive_count_segments(starts, ends, points);
    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
