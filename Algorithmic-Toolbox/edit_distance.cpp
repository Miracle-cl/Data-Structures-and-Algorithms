#include <iostream>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2) {
    //write your code here
    int m = str1.size();
    int n = str2.size();
    // create a table to store results of subproblems
    int dp[m+1][n+1];
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;

    for (int i = 0; i <= n; ++i)
        dp[0][i] = i;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // int insertion = dp[j][i-1] + 1;
            // int deletion = dp[j-1][i] + 1;
            // int match = dp[j-1][i-1];
            // int replace = dp[j-1][i-1] + 1;
            if (str1[j-1] == str2[i-1]) {
                dp[j][i] = dp[j-1][i-1]; // match
            }
            else {
                // insertion, deletion, replace
                dp[j][i] = 1 + min(min(dp[j][i-1], dp[j-1][i]), dp[j-1][i-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
