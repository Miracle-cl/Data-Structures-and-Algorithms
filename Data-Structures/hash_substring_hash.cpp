#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

ull compute_sum(string ss) {
    ull sum = 0;
    for (int i = 0; i < ss.size(); ++i) {
		sum += (int) ss[i];
	}
	return sum;
}

vector<ull> check_sum(string pp, string tt) {
    vector<ull> cs;
    int psize = pp.size();
    int ll = tt.size() - pp.size() + 1;
    cs.push_back( compute_sum(tt.substr(0, psize)) );
    for (int i = 1; i < ll; ++i) {
        ull old_hash = cs[i - 1];
        int left_window = (int) tt[i - 1];
        int right_window = (int) tt[i + pp.size() - 1];
        cs.push_back( old_hash - left_window + right_window );
    }
    return cs;
}


vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    vector<ull> cs = check_sum(s, t);
    int ll = t.size() - s.size() + 1;
    ull pattern_sum = compute_sum(s);
    for (size_t i = 0; i < ll; ++i) {
        if (pattern_sum == cs[i]) {
            if (t.substr(i, s.size()) == s)
                ans.push_back(i);
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
