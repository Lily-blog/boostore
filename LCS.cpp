// Longest Common Subsequence
// ∏¥‘”∂» O(m*n)

#include<bits/stdc++.h>
using namespace std;

int LCS(char* X, char* Y, int m, int n) {
    vector<vector<int> >dp(m + 1, vector<int>(n + 1));
    int i, j;
    for (i = 1; i < m; i++)  dp[i][0] = 0;
    for (j = 0; j < n; j++)  dp[0][j] = 0;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    char X[505], Y[505];
    int m, n;
    cin >> m ;
    cin>>n;
	 
    for (int i = 1; i <= m; i++) {
        cin >> X[i];
    }
    for (int j = 1; j <= n; j++) {
        cin >> Y[j];
    }
    cout << LCS(X, Y, m, n);
    
}

