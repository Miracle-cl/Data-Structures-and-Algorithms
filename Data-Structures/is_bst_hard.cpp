#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    long long key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

// BTS left < key <= right
bool IsBinarySearchTree(const vector<Node>& tree) {
    // Implement correct algorithm here
    if (tree.size() == 0)
        return true;

    // a validate tree with left <= key <= right
    vector<int> stack;
    vector<long long> result;
    int cid = 0;
    while (true) {
        if (cid == -1) {
            stack.push_back(cid);
            cid = tree[cid].left;
        }
        else if (stack.size()) {
            cid = stack.back();
            stack.pop_back();
            if (result.size()) {
                if (result.back() > tree[cid].key)
                    return false;
            }
            result.push_back(tree[cid].key);
            cid = tree[cid].right;
        }
        else
            break;
    }

    // make true left < key
    for (int i = 0; i < tree.size(); ++i) {
        if (tree[i].left != -1) {
            if (tree[i].key <= tree[ tree[i].left ].key)
                return false;
        }
    }

    return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long long key;
    int left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
