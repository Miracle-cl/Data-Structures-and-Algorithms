#include <iostream>
#include <cfloat>
#include <vector>

using namespace std;

int get_change(int money) {
    //write your code here
    vector<int> coins {1, 3, 4};
    vector<int> min_num(money+1);
    min_num[0] = 0;
    for (int m = 1; m <= money; ++m) {
        min_num[m] = m;
        for (int i = 0; i < 3; ++i) {
            if (m >= coins[i]) {
                int num_coins = min_num[m - coins[i]] + 1;
                if (num_coins < min_num[m]) min_num[m] = num_coins;
            }
        }
    }
    return min_num[money];
}

int main() {
    int money;
    cin >> money;
    cout << get_change(money) << '\n';
}
