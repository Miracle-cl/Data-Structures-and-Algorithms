#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
    // Segment(int start, int end) : start(start), end(end) {}
};

bool cmp(struct Segment a, struct Segment b)
{
    return a.start < b.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    sort(segments.begin(), segments.end(), cmp);
    // int l = segments[0].start;
    int r = segments[0].end;
    points.push_back(segments[0].end);
    for (size_t i = 0; i < segments.size(); ++i) {
        if (segments[i].start > r) {
            points.push_back(segments[i].end);
            r = segments[i].end;
        }
        else {
            if (segments[i].end < r) {
                r = segments[i].end;
                points.pop_back();
                points.push_back(r);
            }
        }
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
