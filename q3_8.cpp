#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Initialize the dp table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the first row and first column
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the remaining cells
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "sea";
    string word2 = "eat";
    int result = minDistance(word1, word2);
    cout << "The minimum number of steps required is: " << result << endl;

    return 0;
}
