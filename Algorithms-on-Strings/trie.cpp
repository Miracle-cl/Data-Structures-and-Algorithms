#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

// Good job! (Max time used: 0.01/0.50, max memory used: 67584000/536870912.)

trie build_trie(vector<string> & patterns) {
    trie t;
    // write your code here
    // node -> loc : c
    int loc = 1;
    edges e;
    t.push_back(e);
    for (const string pat : patterns) {
        int node = 0;
        for (int i = 0; i < pat.size(); ++i) {
            if (t.size() <= node) {
                int residual = node - t.size() + 1;
                for (int i = 0; i < residual; ++i)
                    t.push_back(e);
            }

            edges :: iterator it;
            it = t[node].find(pat[i]);
            if (it == t[node].end()) {
                // not in map
                t[node][pat[i]] = loc;
                node = loc;
                loc++;
            }
            else {
                // in map
                node = t[node].at(pat[i]);
            }
        }
    }
    return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
